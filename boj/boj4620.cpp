#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	while (cin >> N, N != -1) {
		cin.ignore();
		vector<string> A(N);
		for (int i = 0; i < N; ++i) {
			getline(cin, A[i]);
		}
		vector<vector<int>> B(N, vector<int>(N));
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < N; ++j) {
				B[i][j] = A[i][j] - '0';
			}
		}
		vector<vector<ll>> dp(N, vector<ll>(N));
		dp[0][0] = 1;
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < N; ++j) {
				if (B[i][j] == 0) {
					continue;
				}
				if (j + B[i][j] < N) {
					dp[i][j + B[i][j]] += dp[i][j];
				}
				if (i + B[i][j] < N) {
					dp[i + B[i][j]][j] += dp[i][j];
				}
			}
		}
		cout << dp[N - 1][N - 1] << "\n";
	}
	return 0;
}
