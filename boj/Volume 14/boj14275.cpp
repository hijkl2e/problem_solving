#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e9 + 7;

int dp[2][65536];

bool solve(int M, int x, int y, int z) {
	for (int i = 0; i < M; ++i) {
		if ((y & (1 << i)) == 0) {
			continue;
		}
		int cnt{};
		cnt += (y >> (i + 1)) & 1;
		cnt += i && ((y >> (i - 1)) & 1);
		cnt += (x >> i) & 1;
		if ((cnt + (z >> i)) % 2) {
			return false;
		}
	}
	return true;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, M{};
	cin >> N >> M;
	vector<int> A;
	for (int i = 0; i < (1 << (2 * M)); ++i) {
		int x = i >> M;
		int y = i & ((1 << M) - 1);
		if ((x & ~y) == 0) {
			A.push_back(i);
		}
	}
	vector<vector<int>> G(1 << (2 * M));
	for (int i = 0; i < A.size(); ++i) {
		int x = A[i] >> M;
		int y = A[i] & ((1 << M) - 1);
		for (int j = 0; j < (1 << M); ++j) {
			if (solve(M, x, y, j)) {
				G[A[i]].push_back(((y & j) << M) | j);
			}
		}
	}
	dp[1][0] = 1;
	for (int i = 0; i <= N; ++i) {
		memcpy(dp[0], dp[1], sizeof dp[1]);
		memset(dp[1], 0, sizeof dp[1]);
		for (int x : A) {
			for (int y : G[x]) {
				dp[1][y] = (dp[1][y] + dp[0][x]) % MOD;
			}
		}
	}
	cout << dp[1][0] << "\n";
	return 0;
}
