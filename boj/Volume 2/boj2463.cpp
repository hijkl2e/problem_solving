#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using edge = tuple<int, int, int>;

const ll MOD = 1e9;

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
	ll unite(int x, int y) {
		x = root(x);
		y = root(y);
		if (x == y) {
			return 0;
		}
		if (sz[x] < sz[y]) {
			swap(x, y);
		}
		par[y] = x;
		ll ret = sz[x] * sz[y];
		sz[x] += sz[y];
		return ret;
	}
	int size(int x) {
		return sz[root(x)];
	}
private:
	vector<int> par;
	vector<ll> sz;
};

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
	UF uf(N + 1);
	vector<ll> A;
	for (auto &[w, u, v] : E) {
		A.push_back(uf.unite(u, v));
	}
	partial_sum(A.begin(), A.end(), A.begin());
	ll ans{};
	for (int i = 0; i < M; ++i) {
		ans += get<0>(E[i]) * A[i] % MOD;
	}
	ans %= MOD;
	cout << ans << "\n";
	return 0;
}
