#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const ll MOD = 1e9 + 7;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, M{};
	cin >> N >> M;
	vector<int> A(M + 1);
	for (int i = 0; i < N; ++i) {
		int x{};
		cin >> x;
		++A[x];
	}
	int maxi{};
	for (int i = 1; i <= M; ++i) {
		if (A[maxi] <= A[i]) {
			maxi = i;
		}
	}
	int maxv = A[maxi];
	vector<vector<ll>> dp(M + 1, vector<ll>(N + 1));
	fill(dp[0].begin(), dp[0].end(), 1);
	for (int i = 1; i <= M; ++i) {
		dp[i][0] = 1;
		for (int j = 1; j <= N; ++j) {
			int x = j - maxv - (i < maxi);
			dp[i][j] = (dp[i][j - 1] + dp[i - 1][j] - (x < 0 ? 0 : dp[i - 1][x]) + MOD) % MOD;
		}
	}
	ll ans = (dp[M][N] - dp[M][N - 1] + MOD) % MOD;
	cout << ans << "\n";
	return 0;
}
