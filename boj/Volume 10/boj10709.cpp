#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, M{};
	cin >> N >> M;
	cin.ignore();
	vector<string> A(N);
	for (int i = 0; i < N; ++i) {
		getline(cin, A[i]);
	}
	vector<vector<int>> dp(N, vector<int>(M, -1));
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			dp[i][j] = A[i][j] == 'c' ? 0 : j == 0 || dp[i][j - 1] == -1 ? -1 : (dp[i][j - 1] + 1);
		}
	}
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			cout << dp[i][j] << (j == M - 1 ? "\n" : " ");
		}
	}
	return 0;
}
