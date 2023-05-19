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
			A[i].second *= -1;
		}
		sort(A.rbegin(), A.rend());
		for (int i = 0; i < N; ++i) {
			A[i].second *= -1;
		}
		vector<int> dp;
		for (int i = 0; i < N; ++i) {
			int j = upper_bound(dp.begin(), dp.end(), A[i].second) - dp.begin();
			if (j == dp.size()) {
				dp.push_back(A[i].second);
			} else {
				dp[j] = A[i].second;
			}
		}
		cout << dp.size() << "\n";
	}
	return 0;
}
