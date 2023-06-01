#include <bits/stdc++.h>

using namespace std;

class UF {
public:
	UF(int N) : par(N), sz(N, 1), f(N) {
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
	int unite(int x, int y) {
		x = root(x);
		y = root(y);
		if (x == y) {
			return 0;
		}
		if (sz[x] < sz[y]) {
			swap(x, y);
		}
		int ret{};
		if (f[x] ^ f[y]) {
			ret = f[x] ? sz[y] : sz[x];
		}
		par[y] = x;
		sz[x] += sz[y];
		return ret;
	}
	int size(int x) {
		return sz[root(x)];
	}
	bool &cycle(int x) {
		return f[root(x)];
	}
private:
	vector<int> par, sz;
	deque<bool> f;
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, Q{};
	cin >> N >> Q;
	UF uf(2 * N);
	int ans{};
	while (Q--) {
		int u{}, v{};
		cin >> u >> v;
		--u, --v;
		ans += uf.unite(2 * u, 2 * v + 1);
		ans += uf.unite(2 * v, 2 * u + 1);
		if (uf.same(2 * u, 2 * u + 1) && !uf.cycle(2 * u)) {
			uf.cycle(2 * u) = true;
			ans += uf.size(2 * u);
		}
		cout << ans / 2 << "\n";
	}
	return 0;
}
