#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T{};
	cin >> T;
	while (T--) {
		int N{};
		cin >> N;
		vector<int> A(N);
		for (int i = 0; i < N; ++i) {
			cin >> A[i];
		}
		int ans{};
		for (int i = 0; i < N; ++i) {
			if (A[i] == ans + 1) {
				++ans;
			}
		}
		ans = N - ans;
		cout << ans << "\n";
	}
	return 0;
}
