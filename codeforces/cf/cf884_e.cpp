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
	int T{};
	cin >> T;
	while (T--) {
		int N{}, M{}, K{};
		cin >> N >> M >> K;
		UF uf(2 * (N + M));
		while (K--) {
			int x1{}, y1{}, x2{}, y2{};
			cin >> x1 >> y1 >> x2 >> y2;
			--x1, --y1, --x2, --y2;
			int u = x1, v = min(y1, y2) + N;
			if (y2 == y1 + 1) {
				uf.unite(u, v + N + M);
				uf.unite(u + N + M, v);
			} else {
				uf.unite(u, v);
				uf.unite(u + N + M, v + N + M);
			}
		}
		bool yes = true;
		for (int i = 0; i < N + M; ++i) {
			if (uf.same(i, i + N + M)) {
				yes = false;
				break;
			}
		}
		cout << (yes ? "YES" : "NO") << "\n";
	}
	return 0;
}
