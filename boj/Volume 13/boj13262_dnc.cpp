#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const ll INF = 4e18;

vector<vector<int>> B;
vector<vector<ll>> dp;

void solve(int L, int R, int optL, int optR) {
	if (L > R) {
		return;
	}
	int j = (L + R) / 2;
	dp[1][j] = -INF;
	int opt{};
	for (int k = optL; k <= optR && k < j; ++k) {
		ll val = dp[0][k] + B[k + 1][j];
		if (dp[1][j] < val) {
			dp[1][j] = val;
			opt = k;
		}
	}
	solve(L, j - 1, optL, opt);
	solve(j + 1, R, opt, optR);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, K{};
	cin >> N >> K;
	vector<int> A(N + 1);
	for (int i = 1; i <= N; ++i) {
		cin >> A[i];
	}
	B.assign(N + 1, vector<int>(N + 1));
	for (int i = 1; i <= N; ++i) {
		for (int j = i; j <= N; ++j) {
			B[i][j] = B[i][j - 1] | A[j];
		}
	}
	dp.assign(2, vector<ll>(N + 1, -INF));
	dp[0][0] = 0;
	for (int i = 1; i <= K; ++i) {
		solve(i, N - K + i, i - 1, N - K + i - 1);
		copy(dp[1].begin(), dp[1].end(), dp[0].begin());
	}
	cout << dp[0][N] << "\n";
	return 0;
}
