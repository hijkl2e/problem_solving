#include <bits/stdc++.h>

using namespace std;

using ll = long long;

ll dp[21][2][5];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	ll N{};
	cin >> N;
	vector<int> A(20);
	for (int i = 19; i > 0; --i) {
		A[i] = N % 10;
		N /= 10;
	}
	string x = "2023x";
	dp[0][0][0] = 1;
	for (int i = 0; i < 20; ++i) {
		for (int j = 0; j < 2; ++j) {
			for (int k = 0; k < 5; ++k) {
				for (int l = 0; l < 10 && (j || l < A[i]); ++l) {
					dp[i + 1][1][k + (l == x[k] - '0')] += dp[i][j][k];
				}
			}
		}
		for (int k = 0; k < 5; ++k) {
			dp[i + 1][0][k + (A[i] == x[k] - '0')] += dp[i][0][k];
		}
	}
	ll ans = dp[20][0][4] + dp[20][1][4];
	cout << ans << "\n";
	return 0;
}
