#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const ll INF = 4e18;

ll N, B, D;
vector<vector<int>> G;
vector<int> sz;

void dfs(int x, int p) {
	for (int y : G[x]) {
		if (y == p) {
			continue;
		}
		dfs(y, x);
		sz[x] += sz[y];
	}
}

ll solve(int x, int p, int d, int h) {
	ll ret = D * (sz[x] - 1);
	if (d == h) {
		return ret;
	}
	ll v1{}, v2{};
	v1 = v2 = B * ((1LL << (h - d)) - 1);
	for (int y : G[x]) {
		if (y == p) {
			continue;
		}
		ll val = solve(y, x, d + 1, h) - D * sz[y];
		if (v1 > val) {
			v2 = v1;
			v1 = val;
		} else if (v2 > val) {
			v2 = val;
		}
	}
	ret += v1 + v2;
	return ret;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> N >> B >> D;
	G.resize(N + 1);
	for (int i = 0; i < N - 1; ++i) {
		int u{}, v{};
		cin >> u >> v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	sz.assign(N + 1, 1);
	dfs(1, -1);
	ll ans = INF;
	for (int i = 1; i < 34; ++i) {
		ans = min(ans, solve(1, -1, 1, i));
	}
	cout << ans << "\n";
	return 0;
}
