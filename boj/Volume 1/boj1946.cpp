#include <bits/stdc++.h>

using namespace std;

using ii = pair<int, int>;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T{};
	cin >> T;
	while (T--) {
		int N{};
		cin >> N;
		vector<ii> A(N);
		for (int i = 0; i < N; ++i) {
			cin >> A[i].first >> A[i].second;
		}
		sort(A.begin(), A.end());
		int x = N + 1, ans{};
		for (int i = 0; i < N; ++i) {
			if (x > A[i].second) {
				x = A[i].second;
				++ans;
			}
		}
		cout << ans << "\n";
	}
	return 0;
}
