#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const ll MOD = 1e9 + 7;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, K{};
	cin >> N >> K;
	vector<int> A(N);
	vector<int> B(N);
	for (int i = 0; i < N; ++i) {
		cin >> A[i] >> B[i];
	}
	vector<vector<ll>> dp(N, vector<ll>(3001));
	fill(dp[0].begin() + A[0], dp[0].begin() + B[0] + 1, 1);
	partial_sum(dp[0].begin(), dp[0].end(), dp[0].begin());
	for (int i = 1; i < N; ++i) {
		for (int j = A[i]; j <= B[i]; ++j) {
			dp[i][j] = (dp[i - 1][min(j + K, 3000)] - dp[i - 1][max(j - K - 1, 0)]) % MOD;
		}
		partial_sum(dp[i].begin(), dp[i].end(), dp[i].begin());
	}
	ll ans = dp[N - 1].back() % MOD;
	cout << ans << "\n";
	return 0;
}
