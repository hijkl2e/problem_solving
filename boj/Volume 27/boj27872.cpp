#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const int INF = 1e9 + 7;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	vector<ll> A(N);
	for (int i = 0; i < N; ++i) {
		cin >> A[i];
	}
	vector<ll> B(47);
	vector<int> C(N, -1);
	vector<int> D;
	for (int i = 0; i < N; ++i) {
		for (int j = 46; j >= 0; --j) {
			if (A[i] & (1LL << j)) {
				if (B[j]) {
					A[i] ^= B[j];
				} else {
					B[j] = A[i];
					C[i] = j;
					D.push_back(j);
					break;
				}
			}
		}
	}
	for (int i = 0; i < 47; ++i) {
		if (B[i] == 0) {
			D.push_back(i);
		}
	}
	reverse(D.begin(), D.end());
	vector<vector<int>> dp(2, vector<int>(1 << 23, -INF));
	vector<vector<ll>> par(2, vector<ll>(1 << 23));
	dp[0][0] = dp[1][0] = 0;
	ll ans{}, cnt = -1;
	for (int z : C) {
		if (z == -1) {
			cout << ans << "\n";
			continue;
		}
		if (++cnt < 23) {
			for (int i = 0; i < (1 << cnt); ++i) {
				ll x = B[z];
				for (int j = 0; j < cnt; ++j) {
					if (i & (1 << j)) {
						x ^= B[D[46 - j]];
					}
				}
				if (__builtin_popcountll(ans) < __builtin_popcountll(x)) {
					ans = x;
				}
			}
		} else if (cnt == 23) {
			for (int i = 23; i < 47; ++i) {
				for (int j = D[i] + 1; j < 47; ++j) {
					if (B[j] & (1LL << D[i])) {
						B[j] ^= B[D[i]];
					}
				}
			}
			for (int i = 23; i < 47; ++i) {
				int x{};
				for (int j = 0; j < 23; ++j) {
					x ^= ((B[D[i]] >> D[j]) & 1) << j;
				}
				for (int j = 0; j < dp[0].size(); ++j) {
					if (dp[0][j] == -INF) {
						continue;
					}
					if (dp[1][j ^ x] < dp[0][j] + 1) {
						dp[1][j ^ x] = dp[0][j] + 1;
						par[1][j ^ x] = par[0][j] ^ B[D[i]];
					}
				}
				copy(dp[1].begin(), dp[1].end(), dp[0].begin());
				copy(par[1].begin(), par[1].end(), par[0].begin());
			}
			for (int i = 0; i < dp[1].size(); ++i) {
				if (__builtin_popcountll(ans) < __builtin_popcount(i) + dp[1][i]) {
					ans = par[1][i];
				}
			}
			D.resize(22);
		} else {
			for (int i = z + 1; i < 47; ++i) {
				if (B[i] & (1LL << z)) {
					B[i] ^= B[z];
				}
			}
			int x{};
			for (int i = 0; i < D.size(); ++i) {
				x ^= ((B[z] >> D[i]) & 1) << i;
			}
			D.pop_back();
			int sz = dp[0].size() / 2;
			for (int i = 0; i < dp[0].size(); ++i) {
				if (dp[0][i] == -INF) {
					continue;
				}
				int k = (i ^ x) & ~sz;
				if (dp[1][k] < dp[0][i] + (i < sz)) {
					dp[1][k] = dp[0][i] + (i < sz);
					par[1][k] = par[0][i] ^ B[z];
				}
			}
			for (int i = sz; i < dp[0].size(); ++i) {
				if (dp[0][i] == -INF) {
					continue;
				}
				int k = i & ~sz;
				if (dp[1][k] < dp[0][i] + 1) {
					dp[1][k] = dp[0][i] + 1;
					par[1][k] = par[0][i];
				}
			}
			for (int i = 0; i < 2; ++i) {
				dp[i].resize(sz);
				par[i].resize(sz);
			}
			copy(dp[1].begin(), dp[1].end(), dp[0].begin());
			copy(par[1].begin(), par[1].end(), par[0].begin());
			for (int i = 0; i < dp[1].size(); ++i) {
				if (__builtin_popcountll(ans) < __builtin_popcount(i) + dp[1][i]) {
					ans = par[1][i];
				}
			}
		}
		cout << ans << "\n";
	}
	return 0;
}
