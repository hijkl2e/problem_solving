#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const ll MOD = 1e9 + 7;

vector<vector<int>> G;
vector<vector<ll>> dp;

vector<ll> mul(vector<ll> &v1, vector<ll> &v2) {
	vector<ll> ret(v1.size());
	for (int i = 0; i < ret.size(); ++i) {
		for (int j = 0; i + j < ret.size(); ++j) {
			ret[i + j] = (ret[i + j] + v1[i] * v2[j]) % MOD;
		}
	}
	return ret;
}

void dfs(int x, int p) {
	dp[x][1] = 1;
	for (int y : G[x]) {
		if (y == p || G[y].empty()) {
			continue;
		}
		dfs(y, x);
		dp[x] = mul(dp[x], dp[y]);
	}
	dp[x][0] = 1;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, K{};
	cin >> N >> K;
	if (K == 1) {
		cout << N << "\n";
		return 0;
	}
	G.resize(N + 1);
	for (int i = 0; i < N - 1; ++i) {
		int u{}, v{};
		cin >> u >> v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	ll ans{};
	for (int i = K; i <= N; ++i) {
		dp.assign(N + 1, vector<ll>(K + 1));
		for (int j = 1; j <= N; ++j) {
			if (G[j].size() == 1) {
				dfs(j, -1);
				ans = (ans + dp[j][K]) % MOD;
				int x = G[j][0];
				auto it = find(G[x].begin(), G[x].end(), j);
				G[x].erase(it);
				G[j].clear();
				break;
			}
		}
	}
	cout << ans << "\n";
	return 0;
}
