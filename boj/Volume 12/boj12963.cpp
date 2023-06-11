#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ii = pair<int, int>;

const ll MOD = 1e9 + 7;

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

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, M{};
	cin >> N >> M;
	vector<ii> E(M);
	for (auto &[u, v] : E) {
		cin >> u >> v;
	}
	vector<ll> A(M + 1);
	A[0] = 1;
	for (int i = 1; i < M; ++i) {
		A[i] = 3 * A[i - 1] % MOD;
	}
	UF uf(N);
	ll ans{};
	for (int i = M - 1; i >= 0; --i) {
		auto &[u, v] = E[i];
		if ((uf.same(u, 0) && uf.same(v, N - 1)) || (uf.same(v, 0) && uf.same(u, N - 1))) {
			ans = (ans + A[i]) % MOD;
		} else {
			uf.unite(u, v);
		}
	}
	cout << ans << "\n";
	return 0;
}
