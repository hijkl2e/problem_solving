#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> dp(37, vector<int>(37));
vector<int> D{
	1, 1, 2, 2, 8, 13, 13, 10, 26, 26, 17, 25, 25,
	1, 14, 14, 8, 1, 1, 19, 2, 2, 17, 13, 13, 1, 26
};
vector<int> E{
	0, 1, 14, 0, 7, 11, 0, 4, 17, 0, 19, 5, 0, 25,
	2, 0, 22, 8, 0, 10, 23, 0, 16, 20, 0, 13, 26
};

int solve27(int N) {
	int ret = 1;
	while (N) {
		ret = ret * (N / 27 % 2 ? 26 : 1) * D[N % 27] % 27;
		N /= 3;
	}
	return ret;
}

int solve27(int N, int K) {
	int cnt{};
	for (int i = 3; i <= N; i *= 3) {
		cnt += N / i - (N - K) / i - K / i;
	}
	int ret = cnt == 0 ? 1 : cnt == 1 ? 3 : cnt == 2 ? 9 : 0;
	ret = ret * solve27(N) * E[solve27(N - K) * solve27(K) % 27] % 27;
	return ret;
}

int solve(int N, int K, int M) {
	if (M == 27) {
		return solve27(N, K);
	}
	int ret = 1;
	while (N) {
		ret = ret * dp[N % M][K % M] % M;
		N /= M, K /= M;
	}
	return ret;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	for (int i = 0; i < dp.size(); ++i) {
		dp[i][0] = dp[i][i] = 1;
		for (int j = 1; j < i; ++j) {
			dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j]) % 142857;
		}
	}
	vector<int> A{27, 11, 13, 37};
	vector<int> B{137566, 103896, 109890, 77220};
	int T{};
	cin >> T;
	while (T--) {
		int N{}, K{};
		cin >> N >> K;
		vector<int> C(4);
		for (int i = 0; i < 4; ++i) {
			C[i] = solve(N, K, A[i]);
		}
		int ans{};
		for (int i = 0; i < 4; ++i) {
			ans += B[i] * C[i];
		}
		ans %= 142857;
		cout << ans << "\n";
	}
	return 0;
}
