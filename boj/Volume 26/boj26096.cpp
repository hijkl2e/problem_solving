#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int D{};
	cin >> D;
	vector<int> A(D);
	for (int i = 0; i < D; ++i) {
		cin >> A[i];
	}
	int S{}, E{};
	cin >> S >> E;
	vector<double> dp(S + E + 1);
	double lo = 1, hi = 3 * E + 1;
	for (int k = 0; k < 30; ++k) {
		double mid = (lo + hi) / 2;
		for (int i = S + E - 1; i >= 0; --i) {
			if (i >= S) {
				dp[i] = i > E ? mid : 0;
			} else {
				dp[i] = 1e9;
				for (int j = 0; j < D; ++j) {
					dp[i] = min(dp[i], (dp[i + 1] - dp[i + A[j] + 1]) / A[j]);
				}
				++dp[i];
			}
			dp[i] += dp[i + 1];
		}
		if (dp[0] - dp[1] > mid) {
			lo = mid;
		} else {
			hi = mid;
		}
	}
	cout << fixed << setprecision(10);
	cout << lo << "\n";
	return 0;
}
