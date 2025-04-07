#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ii = pair<int, int>;
using edge = tuple<int, int, int>;

class UF {
public:
	UF(int N) : par(N), sz(N, 1) {
		for (int i = 0; i < N; ++i) {
			par[i] = i;
		}
	}
	int root(int x) {
		return par[x] == x ? x : (par[x] = root(par[x]));
	}
	bool same(int x, int y) {
		return root(x) == root(y);
	}
	bool unite(int x, int y) {
		x = root(x);
		y = root(y);
		if (x == y) {
			return false;
		}
		if (sz[x] < sz[y]) {
			swap(x, y);
		}
		par[y] = x;
		sz[x] += sz[y];
		return true;
	}
	int size(int x) {
		return sz[root(x)];
	}
private:
	vector<int> par, sz;
};

vector<vector<ii>> G;
vector<ll> D;

void dfs(int u, int p) {
	for (auto &[v, w] : G[u]) {
		if (D[v] == -1) {
			D[v] = D[u] + w;
			dfs(v, u);
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, M{};
	cin >> N >> M;
	vector<edge> E(M);
	for (auto &[w, u, v] : E) {
		cin >> u >> v >> w;
	}
	sort(E.rbegin(), E.rend());
	ll ans{};
	UF uf(N + 1);
	G.resize(N + 1);
	for (auto &[w, u, v] : E) {
		if (uf.unite(u, v)) {
			G[u].push_back({v, w});
			G[v].push_back({u, w});
			ans += w;
		}
	}
	ans *= 2;
	int r{};
	cin >> r;
	D.assign(N + 1, -1);
	D[r] = 0;
	dfs(r, -1);
	ans -= *max_element(D.begin(), D.end());
	cout << ans << "\n";
	return 0;
}
