#include <bits/stdc++.h>

using namespace std;

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

int solve(int N, vector<edge> &E) {
	int ret{};
	UF uf(N + 1);
	for (auto &[w, u, v] : E) {
		if (uf.unite(u, v)) {
			ret += w;
		}
	}
	return ret;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, M{};
	cin >> N >> M;
	vector<edge> E(M + 1);
	for (auto &[w, u, v] : E) {
		cin >> u >> v >> w;
		w ^= 1;
	}
	sort(E.begin(), E.end());
	int res1 = solve(N, E);
	reverse(E.begin(), E.end());
	int res2 = solve(N, E);
	int ans = res2 * res2 - res1 * res1;
	cout << ans << "\n";
	return 0;
}
