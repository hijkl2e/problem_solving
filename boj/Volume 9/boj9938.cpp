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
			return f[x] ? false : (f[x] = true);
		} else if (f[x] && f[y]) {
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
private:
	vector<int> par, sz;
	deque<bool> f;
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, L{};
	cin >> N >> L;
	UF uf(L + 1);
	while (N--) {
		int a{}, b{};
		cin >> a >> b;
		a = uf.root(a);
		b = uf.root(b);
		bool yes = uf.unite(a, b);
		cout << (yes ? "LADICA" : "SMECE") << "\n";
	}
	return 0;
}
