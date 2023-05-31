#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e6 + 7;

int dp[53][53][53][53];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, M{}, K{};
	cin >> N >> M >> K;
	vector<vector<int>> A(N, vector<int>(M));
	for (int i = 0; i < K; ++i) {
		int x{}, y{};
		cin >> x >> y;
		A[x - 1][y - 1] = i + 1;
	}
	dp[A[0][0] ? 1 : 0][A[0][0]][0][0] = 1;
	for (int i = 0; i <= K; ++i) {
		for (int j = 0; j <= K; ++j) {
			for (int k = 0; k < N; ++k) {
				for (int l = 0; l < M; ++l) {
					if (k + 1 < N && (A[k + 1][l] == 0 || j < A[k + 1][l])) {
						int &val = A[k + 1][l] ? dp[i + 1][A[k + 1][l]][k + 1][l] : dp[i][j][k + 1][l];
						val = (val + dp[i][j][k][l]) % MOD;
					}
					if (l + 1 < M && (A[k][l + 1] == 0 || j < A[k][l + 1])) {
						int &val = A[k][l + 1] ? dp[i + 1][A[k][l + 1]][k][l + 1] : dp[i][j][k][l + 1];
						val = (val + dp[i][j][k][l]) % MOD;
					}
				}
			}
		}
	}
	vector<int> B(K + 1);
	for (int i = 0; i <= K; ++i) {
		for (int j = 0; j <= K; ++j) {
			B[i] = (B[i] + dp[i][j][N - 1][M - 1]) % MOD;
		}
	}
	for (int i = 0; i <= K; ++i) {
		cout << B[i] << (i == K ? "\n" : " ");
	}
	return 0;
}
