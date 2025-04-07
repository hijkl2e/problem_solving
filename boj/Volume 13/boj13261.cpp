#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const ll INF = 4e18;

vector<ll> C;
vector<vector<ll>> dp;

void solve(int L, int R, int optL, int optR) {
	if (L > R) {
		return;
	}
	int j = (L + R) / 2;
	dp[1][j] = INF;
	int opt{};
	for (int k = optL; k <= optR && k < j; ++k) {
		ll val = dp[0][k] + (C[j] - C[k]) * (j - k);
		if (dp[1][j] > val) {
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
	int L{}, G{};
	cin >> L >> G;
	G = min(G, L);
	C.resize(L + 1);
	for (int i = 1; i <= L; ++i) {
		cin >> C[i];
	}
	partial_sum(C.begin(), C.end(), C.begin());
	dp.assign(2, vector<ll>(L + 1, INF));
	dp[0][0] = 0;
	for (int i = 1; i <= G; ++i) {
		solve(i, L - G + i, i - 1, L - G + i - 1);
		copy(dp[1].begin(), dp[1].end(), dp[0].begin());
	}
	cout << dp[0][L] << "\n";
	return 0;
}
