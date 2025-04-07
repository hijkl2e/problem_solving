#include <bits/stdc++.h>

using namespace std;

bool solve(int x, int y) {
	while (y) {
		int u = x & -x;
		int v = y & -y;
		if (u > v) {
			return false;
		}
		x -= u, y -= v;
	}
	return true;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int K{};
	while (cin >> K) {
		vector<int> A(K);
		for (int i = 0; i < K; ++i) {
			cin >> A[i];
		}
		int N{};
		cin >> N;
		vector<int> B(A[0] + 1);
		B[0] = K;
		for (int i = 1; i < B.size(); ++i) {
			B[i] = B[i - 1];
			while (A[B[i] - 1] < i) {
				--B[i];
			}
		}
		vector<vector<int>> C(N + 1);
		for (int i = 1; i < (1 << N); ++i) {
			int x = __builtin_popcount(i);
			C[x].push_back(i);
		}
		vector<vector<int>> dp(B.size(), vector<int>(1 << N));
		dp[0][(1 << K) - 1] = true;
		for (int i = 1; i < dp.size(); ++i) {
			for (int x : C[B[i - 1]]) {
				for (int y : C[B[i]]) {
					if (solve(x, y)) {
						dp[i][y] += dp[i - 1][x];
					}
				}
			}
		}
		int ans{};
		for (int i = 0; i < (1 << N); ++i) {
			ans += dp.back()[i];
		}
		cout << ans << "\n";
	}
	return 0;
}
