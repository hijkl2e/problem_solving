#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	while (cin >> N, N) {
		vector<int> A(N);
		vector<int> B(N);
		for (int i = 0; i < N; ++i) {
			double x{};
			cin >> A[i] >> x;
			B[i] = lround(100 * x);
		}
		vector<int> dp(N);
		vector<int> par(N);
		for (int i = 0; i < N; ++i) {
			if (i && dp[i - 1] - 8 * (A[i] - A[i - 1] - 1) > 0) {
				dp[i] = dp[i - 1] - 8 * (A[i] - A[i - 1]) + B[i];
				par[i] = par[i - 1];
			} else {
				dp[i] = B[i] - 8;
				par[i] = i;
			}
		}
		int p = max_element(dp.begin(), dp.end()) - dp.begin();
		for (int i = 0; i < N; ++i) {
			if (dp[i] == dp[p] && A[i] - A[par[i]] < A[p] - A[par[p]]) {
				p = i;
			}
		}
		if (dp[p] > 0) {
			cout << dp[p] / 100 << "." << setfill('0') << setw(2) << dp[p] % 100;
			cout << " " << A[par[p]] << " " << A[p] << "\n";
		} else {
			cout << "no profit\n";
		}
	}
	return 0;
}
