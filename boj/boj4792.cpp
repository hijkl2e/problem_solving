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
	int N{}, M{}, K{};
	while (cin >> N >> M >> K, N) {
		UF uf1(N + 1);
		UF uf2(N + 1);
		int r{}, b{};
		while (M--) {
			char c{};
			int u{}, v{};
			cin >> c >> u >> v;
			if (c == 'R' && uf1.unite(u, v)) {
				++r;
			} else if (c == 'B' && uf2.unite(u, v)) {
				++b;
			}
		}
		cout << (N - r - 1 <= K && K <= b) << "\n";
	}
	return 0;
}
