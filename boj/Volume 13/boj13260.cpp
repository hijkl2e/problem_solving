#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const ll INF = 4e18;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, M{};
	cin >> N >> M;
	vector<int> A(M + 2);
	for (int i = 1; i <= M; ++i) {
		cin >> A[i];
	}
	A[M + 1] = N;
	sort(A.begin(), A.end());
	vector<vector<ll>> dp(M + 1, vector<ll>(M + 2, INF));
	vector<vector<int>> opt(M + 1, vector<int>(M + 2));
	for (int i = 0; i <= M; ++i) {
		dp[i][i + 1] = 0;
		opt[i][i + 1] = i;
	}
	for (int i = M - 1; i >= 0; --i) {
		for (int j = i + 2; j < M + 2; ++j) {
			for (int k = opt[i][j - 1]; k <= opt[i + 1][j]; ++k) {
				ll val = dp[i][k] + dp[k][j];
				if (dp[i][j] > val) {
					dp[i][j] = val;
					opt[i][j] = k;
				}
			}
			dp[i][j] += A[j] - A[i];
		}
	}
	cout << dp[0][M + 1] << "\n";
	return 0;
}
