#include <bits/stdc++.h>

using namespace std;

using ii = pair<int, int>;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	vector<ii> A(N);
	for (int i = 0; i < N; ++i) {
		cin >> A[i].first >> A[i].second;
	}
	sort(A.begin(), A.end());
	int ans{};
	for (int i = 0, j = 0; j < N; ++i) {
		if (i % 7 < 5 && --A[j].second == 0) {
			++j;
		}
		while (j < N && A[j].first == i + 1) {
			ans += A[j].second;
			if (ans > i + 1) {
				ans = -1;
				j = N;
				break;
			}
			++j;
		}
	}
	cout << ans << "\n";
	return 0;
}
