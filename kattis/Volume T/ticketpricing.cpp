#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9 + 7;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, M{};
	cin >> N >> M;
	vector<vector<int>> A(M + 1);
	vector<vector<int>> B(M + 1);
	for (int i = 0; i <= M; ++i) {
		int K{};
		cin >> K;
		A[i].resize(K);
		B[i].resize(K);
		for (int j = 0; j < K; ++j) {
			cin >> A[i][j];
		}
		for (int j = 0; j < K; ++j) {
			cin >> B[i][j];
		}
	}
	vector<vector<int>> dp(M + 2, vector<int>(N + 1, -1));
	vector<vector<int>> par(M + 2, vector<int>(N + 1, INF));
	dp[0][N] = 0;
	for (int i = 0; i <= M; ++i) {
		for (int j = 0; j <= N; ++j) {
			if (dp[i][j] == -1) {
				continue;
			}
			for (int k = 0; k < A[i].size(); ++k) {
				int x = min(j, B[i][k]);
				int &val = dp[i + 1][j - x];
				int nval = dp[i][j] + x * A[i][k];
				int &p = par[i + 1][j - x];
				if (val <= nval) {
					p = min(val == nval ? p : INF, i ? par[i][j] : k);
					val = nval;
				}
			}
		}
	}
	int maxv = *max_element(dp[M + 1].begin(), dp[M + 1].end());
	int p = INF;
	for (int i = 0; i <= N; ++i) {
		if (dp[M + 1][i] == maxv) {
			p = min(p, par[M + 1][i]);
		}
	}
	cout << maxv << "\n" << A[0][p] << "\n";
	return 0;
}
