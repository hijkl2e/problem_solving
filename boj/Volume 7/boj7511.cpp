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
	for (int tc = 1; tc <= T; ++tc) {
		if (tc > 1) {
			cout << "\n";
		}
		int N{};
		cin >> N;
		UF uf(N);
		int K{};
		cin >> K;
		while (K--) {
			int u{}, v{};
			cin >> u >> v;
			uf.unite(u, v);
		}
		int M{};
		cin >> M;
		cout << "Scenario " << tc << ":\n";
		while (M--) {
			int u{}, v{};
			cin >> u >> v;
			cout << uf.same(u, v) << "\n";
		}
	}
	return 0;
}
