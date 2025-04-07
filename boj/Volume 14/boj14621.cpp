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

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, M{};
	cin >> N >> M;
	deque<bool> A(N + 1);
	for (int i = 1; i <= N; ++i) {
		char c{};
		cin >> c;
		A[i] = c == 'M';
	}
	vector<edge> E;
	while (M--) {
		int u{}, v{}, w{};
		cin >> u >> v >> w;
		if (A[u] ^ A[v]) {
			E.push_back({w, u, v});
		}
	}
	sort(E.begin(), E.end());
	UF uf(N + 1);
	int ans{};
	for (auto &[w, u, v] : E) {
		if (uf.unite(u, v)) {
			ans += w;
		}
	}
	cout << (uf.size(1) == N ? ans : -1) << "\n";
	return 0;
}
