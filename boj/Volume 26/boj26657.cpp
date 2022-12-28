#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const ll INF = 1e18;

vector<vector<ll>> X(11);
ll dp[11][101][101];

ll solve(ll K, ll M, ll D, ll N) {
	if (N == 0) {
		return 1;
	} else if (N > D) {
		return 0;
	}
	if (K == X[M][D] - 1) {
		ll &ret = dp[M][D][N];
		if (ret != -1) {
			return ret;
		}
		ret = 1;
		for (int i = 1; i <= N; ++i) {
			ret = ret * (D - N + i) / i * (M - 1);
		}
		return ret;
	}
	if (K > X[M][--D] - 1) {
		return solve(X[M][D] - 1, M, D, N) + (K / X[M][D] - 1) * solve(X[M][D] - 1, M, D, N - 1)
				+ solve(K % X[M][D], M, D, N - 1);
	} else {
		return solve(K, M, D, N);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	for (int i = 2; i < 11; ++i) {
		X[i].push_back(1);
		while (X[i].back() < INF) {
			X[i].push_back(i * X[i].back());
		}
	}
	memset(dp, -1, sizeof dp);
	int T{};
	cin >> T;
	while (T--) {
		ll A{}, B{}, M{}, N{};
		cin >> A >> B >> M >> N;
		ll ans = solve(B, M, X[M].size() - 1, N) - solve(A - 1, M, X[M].size() - 1, N);
		cout << ans << "\n";
	}
	return 0;
}
