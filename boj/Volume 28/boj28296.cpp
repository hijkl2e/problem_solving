#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using edge = tuple<int, int, int>;

vector<ll> A;

class UF {
public:
	UF(int N) : par(N), sz(N, 1), c(N) {
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
	bool unite(int x, int y, int w) {
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
		for (auto &[u, v] : c[y]) {
			A[u] += 1LL * c[x][u] * v * w;
			c[x][u] += v;
		}
		c[y].clear();
		return true;
	}
	int size(int x) {
		return sz[root(x)];
	}
	map<int, int> &C(int x) {
		return c[root(x)];
	}
private:
	vector<int> par, sz;
	vector<map<int, int>> c;
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, K{}, M{};
	cin >> N >> K >> M;
	vector<int> C(N + 1);
	for (int i = 1; i <= N; ++i) {
		cin >> C[i];
	}
	vector<edge> E(M);
	for (auto &[w, u, v] : E) {
		cin >> u >> v >> w;
	}
	sort(E.rbegin(), E.rend());
	UF uf(N + 1);
	for (int i = 1; i <= N; ++i) {
		uf.C(i).insert({C[i], 1});
	}
	A.resize(K + 1);
	for (auto &[w, u, v] : E) {
		uf.unite(u, v, w);
	}
	for (int i = 1; i <= K; ++i) {
		cout << A[i] << "\n";
	}
	return 0;
}
