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
	int N{};
	cin >> N;
	UF uf(N + 1);
	for (int i = 0; i < N - 2; ++i) {
		int u{}, v{};
		cin >> u >> v;
		uf.unite(u, v);
	}
	int x{}, y{};
	for (int i = 1; i <= N; ++i) {
		if (uf.root(i) == i) {
			x = i;
			swap(x, y);
		}
	}
	cout << x << " " << y << "\n";
	return 0;
}
