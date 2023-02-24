#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, D{}, R{};
	cin >> N >> D >> R;
	vector<vector<double>> nCr(N + D, vector<double>(N + D));
	for (int i = 0; i < nCr.size(); ++i) {
		nCr[i][0] = nCr[i][i] = 1;
		for (int j = 1; j < i; ++j) {
			nCr[i][j] = nCr[i - 1][j - 1] + nCr[i - 1][j];
		}
	}
	vector<vector<double>> dp(N + 1, vector<double>(D + 1));
	for (int i = 1; i <= N; ++i) {
		for (int j = 0; j <= D; ++j) {
			if (i <= R) {
				dp[i][j] = (i + j) * nCr[i + j - 1][j];
				continue;
			}
			dp[i][j] = nCr[i + j - 1][j] * R;
			for (int k = max(i - j, 0); k < i; ++k) {
				dp[i][j] += nCr[i][k] * dp[i - k][j - i + k];
			}
		}
	}
	double ans = dp[N][D] / nCr[N + D - 1][D];
	cout << fixed << setprecision(10);
	cout << ans << "\n";
	return 0;
}
