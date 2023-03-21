#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> nCr(int sz) {
	vector<vector<int>> dp(sz, vector<int>(sz + 1));
	for (int i = 0; i < sz; ++i) {
		dp[i][0] = dp[i][i] = 1;
		for (int j = 1; j < i; ++j) {
			dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j]) % sz;
		}
	}
	return dp;
}

int solve(vector<vector<int>> &nCr, int N, int K) {
	int ret = 1, sz = nCr.size();
	while (N) {
		ret = ret * nCr[N % sz][K % sz] % sz;
		N /= sz, K /= sz;
	}
	return ret;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	vector<vector<int>> nCr1 = nCr(97);
	vector<vector<int>> nCr2 = nCr(1031);
	int T{};
	cin >> T;
	while (T--) {
		int N{}, M{};
		cin >> N >> M;
		if (M > N + 1) {
			cout << "0\n";
			continue;
		} else if (M == 1) {
			cout << (N == 0) << "\n";
			continue;
		}
		int x = solve(nCr1, N - 1, M - 2);
		int y = solve(nCr2, N - 1, M - 2);
		int ans = (36085 * x + 63923 * y) % 100007;
		cout << ans << "\n";
	}
	return 0;
}
