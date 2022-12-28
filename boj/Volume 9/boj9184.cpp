#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int dp[21][21][21]{};
	for (int i = 0; i < 21; ++i) {
		for (int j = 0; j < 21; ++j) {
			for (int k = 0; k < 21; ++k) {
				if (i == 0 || j == 0 || k == 0) {
					dp[i][j][k] = 1;
				} else if (i < j && j < k) {
					dp[i][j][k] = dp[i][j][k - 1] + dp[i][j - 1][k - 1] - dp[i][j - 1][k];
				} else {
					dp[i][j][k] = dp[i - 1][j][k] + dp[i - 1][j - 1][k]
								+ dp[i - 1][j][k - 1] - dp[i - 1][j - 1][k - 1];
				}
			}
		}
	}
	int a{}, b{}, c{};
	while (cin >> a >> b >> c, a != -1 || b != -1 || c != -1) {
		int ans{};
		if (a <= 0 || b <= 0 || c <= 0) {
			ans = 1;
		} else if (a > 20 || b > 20 || c > 20) {
			ans = dp[20][20][20];
		} else {
			ans = dp[a][b][c];
		}
		cout << "w(" << a << ", " << b << ", " << c << ") = " << ans << "\n";
	}
	return 0;
}
