#include <bits/stdc++.h>

using namespace std;

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
	int N{}, M{}, Q{};
	cin >> N >> M >> Q;
	UF uf(2 * N);
	while (M--) {
		int u{}, v{}, w{};
		cin >> u >> v >> w;
		--u, --v;
		uf.unite(2 * u, 2 * v + 1);
		uf.unite(2 * v, 2 * u + 1);
	}
	while (Q--) {
		int u{}, v{}, k{};
		cin >> u >> v >> k;
		--u, --v;
		bool yes = uf.same(2 * u, 2 * v) || (k % 2 && uf.same(2 * u, 2 * v + 1));
		cout << (yes ? "Yes" : "No") << "\n";
	}
	return 0;
}
