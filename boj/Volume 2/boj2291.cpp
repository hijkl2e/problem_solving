#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, M{}, K{};
	cin >> N >> M >> K;
	M -= N;
	vector<vector<int>> dp(N + 1, vector<int>(M + 1));
	dp[0][0] = 1;
	for (int i = 1; i <= N; ++i) {
		for (int j = 0; j <= M; ++j) {
			for (int k = 0; i * k <= j; ++k) {
				dp[i][j] += dp[i - 1][j - i * k];
			}
		}
	}
	vector<int> A(N);
	for (int i = 0; i < N; ++i) {
		A[i] = i ? A[i - 1] : 1;
		while (K > dp[N - i - 1][M]) {
			K -= dp[N - i - 1][M];
			M -= N - i;
			++A[i];
		}
	}
	for (int i = 0; i < N; ++i) {
		cout << A[i] << (i == N - 1 ? "\n" : " ");
	}
	return 0;
}
