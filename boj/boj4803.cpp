#include <bits/stdc++.h>

using namespace std;

class UF {
public:
	UF(int N) : par(N), sz(N, 1), f(N) {
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
			f[x] = true;
			return false;
		}
		if (sz[x] < sz[y]) {
			swap(x, y);
		}
		par[y] = x;
		sz[x] += sz[y];
		f[x] |= f[y];
		return true;
	}
	int size(int x) {
		return sz[root(x)];
	}
	bool F(int x) {
		return f[root(x)];
	}
private:
	vector<int> par, sz;
	deque<bool> f;
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, M{};
	for (int tc = 1; cin >> N >> M, N; ++tc) {
		UF uf(N + 1);
		while (M--) {
			int u{}, v{};
			cin >> u >> v;
			uf.unite(u, v);
		}
		int ans{};
		for (int i = 1; i <= N; ++i) {
			if (uf.root(i) == i && !uf.F(i)) {
				++ans;
			}
		}
		cout << "Case " << tc << ": ";
		if (ans > 1) {
			cout << "A forest of " << ans << " trees.\n";
		} else if (ans == 1) {
			cout << "There is one tree.\n";
		} else {
			cout << "No trees.\n";
		}
	}
	return 0;
}
