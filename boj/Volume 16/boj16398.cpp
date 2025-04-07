#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using edge = tuple<int, int, int>;

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
	vector<vector<int>> C(N, vector<int>(N));
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			cin >> C[i][j];
		}
	}
	vector<edge> E;
	for (int i = 0; i < N; ++i) {
		for (int j = i + 1; j < N; ++j) {
			E.push_back({C[i][j], i, j});
		}
	}
	sort(E.begin(), E.end());
	UF uf(N);
	ll ans{};
	for (auto &[w, u, v] : E) {
		if (uf.unite(u, v)) {
			ans += w;
		}
	}
	cout << ans << "\n";
	return 0;
}
