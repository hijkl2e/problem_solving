#include <bits/stdc++.h>

using namespace std;

class UF {
public:
	UF(int N) : par(N), sz(N, 1), nxt(N) {
		for (int i = 0; i < N; ++i) {
			par[i] = nxt[i] = i;
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
		nxt[x] = min(nxt[x], nxt[y]);
		return true;
	}
	int size(int x) {
		return sz[root(x)];
	}
	int next(int x) {
		return nxt[root(x)];
	}
private:
	vector<int> par, sz, nxt;
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int G{}, P{};
	cin >> G >> P;
	UF uf(G + 1);
	int ans = P;
	for (int i = 0; i < P; ++i) {
		int x{};
		cin >> x;
		x = uf.next(x);
		if (x) {
			uf.unite(x, x - 1);
		} else {
			ans = i;
			break;
		}
	}
	cout << ans << "\n";
	return 0;
}
