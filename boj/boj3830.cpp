#include <bits/stdc++.h>

using namespace std;

class UF {
public:
	UF(int N) : par(N), sz(N, 1), wt(N) {
		for (int i = 0; i < N; ++i) {
			par[i] = i;
		}
	}
	int root(int x) {
		return par[x] == x ? x : root(par[x]);
	}
	bool same(int x, int y) {
		return root(x) == root(y);
	}
	bool unite(int x, int y, int w) {
		w += weight(y) - weight(x);
		x = root(x);
		y = root(y);
		if (x == y) {
			return false;
		}
		if (sz[x] > sz[y]) {
			swap(x, y);
			w *= -1;
		}
		par[x] = y;
		sz[y] += sz[x];
		wt[x] = w;
		return true;
	}
	int size(int x) {
		return sz[root(x)];
	}
	int weight(int x) {
		int ret{};
		while (par[x] != x) {
			ret += wt[x];
			x = par[x];
		}
		return ret;
	}
private:
	vector<int> par, sz, wt;
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, M{};
	while (cin >> N >> M, N) {
		UF uf(N + 1);
		while (M--) {
			char c{};
			int a{}, b{}, w{};
			cin >> c >> a >> b;
			if (c == '!') {
				cin >> w;
				uf.unite(a, b, w);
			} else if (uf.same(a, b)) {
				int ans = uf.weight(a) - uf.weight(b);
				cout << ans << "\n";
			} else {
				cout << "UNKNOWN\n";
			}
		}
	}
	return 0;
}
