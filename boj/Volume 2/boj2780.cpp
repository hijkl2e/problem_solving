#include <bits/stdc++.h>

using namespace std;

const int MOD = 1234567;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	vector<int> A{
		0x080, 0x014, 0x02a, 0x044, 0x0a2,
		0x154, 0x228, 0x111, 0x2a0, 0x140
	};
	vector<vector<int>> dp(1001, vector<int>(10));
	fill(dp[1].begin(), dp[1].end(), 1);
	for (int i = 2; i < dp.size(); ++i) {
		for (int j = 0; j < 10; ++j) {
			for (int k = 0; k < 10; ++k) {
				if (A[j] & (1 << k)) {
					dp[i][j] = (dp[i][j] + dp[i - 1][k]) % MOD;
				}
			}
		}
	}
	vector<int> B(1001);
	for (int i = 1; i < B.size(); ++i) {
		B[i] = accumulate(dp[i].begin(), dp[i].end(), 0) % MOD;
	}
	int T{};
	cin >> T;
	while (T--) {
		int N{};
		cin >> N;
		cout << B[N] << "\n";
	}
	return 0;
}
