#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using edge = tuple<int, int, int>;

const ll MOD = 998244353;

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

ll pow(ll x, ll y) {
	ll ret = 1;
	while (y) {
		if (y % 2) {
			ret = ret * x % MOD;
		}
		x = x * x % MOD;
		y /= 2;
	}
	return ret;
}

int N;
vector<vector<ll>> L;

ll solve() {
	ll ret = 1;
	for (int i = 1; i < N; ++i) {
		ll x = pow(L[i][i], MOD - 2);
		for (int j = i + 1; j < N; ++j) {
			if (L[j][i] == 0) {
				continue;
			}
			ll y = L[j][i] * x % MOD;
			for (int k = i; k < N; ++k) {
				L[j][k] = (L[j][k] - y * L[i][k]) % MOD;
			}
		}
		ret = ret * L[i][i] % MOD;
	}
	ret = (ret + MOD) % MOD;
	return ret;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int M{};
	cin >> N >> M;
	vector<edge> E(M);
	for (auto &[w, u, v] : E) {
		cin >> u >> v >> w;
	}
	sort(E.begin(), E.end());
	UF uf(N + 1);
	L.assign(N + 1, vector<ll>(N + 1));
	ll ans = 1;
	for (int i = 0, j = 0; i < M; i = j) {
		int now = get<0>(E[i]);
		while (j < M && get<0>(E[j]) == now) {
			++j;
		}
		for (int k = i; k < j; ++k) {
			auto &[w, u, v] = E[k];
			if (uf.same(u, v)) {
				continue;
			}
			u = uf.root(u);
			v = uf.root(v);
			++L[u][u], ++L[v][v];
			--L[u][v], --L[v][u];
		}
		int cnt{};
		for (int k = i; k < j; ++k) {
			auto &[w, u, v] = E[k];
			if (uf.unite(u, v)) {
				++cnt;
			}
		}
		while (cnt) {
			ans = ans * cnt-- % MOD;
		}
	}
	ans = ans * solve() % MOD;
	cout << ans << "\n";
	return 0;
}
