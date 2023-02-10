#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const ll MOD = 998244353;

vector<vector<int>> A;

bool chk(int u, int v) {
	return A[0][u] == v || (A[0][u] == -1 && A[1][v] == -1);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, K{};
	cin >> N >> K;
	A.assign(2, vector<int>(N + 1, -1));
	while (K--) {
		int u{}, v{};
		cin >> u >> v;
		A[0][u] = v;
		A[1][v] = u;
	}
	vector<vector<ll>> dp(N + 1, vector<ll>(3));
	dp[0][2] = 1;
	dp[1][2] = chk(1, 1);
	vector<ll> sum(4);
	vector<int> cnt(2);
	for (int i = 2; i <= N; ++i) {
		if (chk(i, i)) {
			dp[i][2] += dp[i - 1][2];
		}
		if (chk(i, i - 1) && chk(i - 1, i)) {
			dp[i][2] += dp[i - 2][2];
		}
		for (int j = 0; j < 2; ++j) {
			int k = j ^ 1;
			if (A[k][i] == -1) {
				dp[i][j] += sum[j] + sum[j + 2];
			} else if (A[k][i] < i - 1 && cnt[j] >= A[k][i] - i - 2) {
				dp[i][j] += dp[A[k][i] + 1][k];
				if (cnt[j] >= A[k][i] - i - 1) {
					dp[i][j] += dp[A[k][i] - 1][2];
				}
			}
			if (chk(i - j, i - k)) {
				dp[i][2] += dp[i][j];
			}
		}
		for (int j = 0; j < 3; ++j) {
			dp[i][j] %= MOD;
		}
		for (int j = 0; j < 2; ++j) {
			int k = j ^ 1;
			if (chk(i - j, i - k)) {
				if (A[j][i - 1] == -1) {
					sum[j] += dp[i - 2][2];
				}
				++cnt[j];
			} else {
				sum[j] = sum[j + 2] = cnt[j] = 0;
			}
			if (A[j][i - 1] == -1) {
				sum[j + 2] += dp[i][k];
			}
		}
		for (int j = 0; j < 4; ++j) {
			sum[j] %= MOD;
		}
	}
	cout << dp[N][2] << "\n";
	return 0;
}
