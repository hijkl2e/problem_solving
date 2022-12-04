#include <bits/stdc++.h>

using namespace std;

using ll = long long;

class UF {
public:
	UF(int N) : par(2 * N + 1), sz(2 * N + 1, 1), sm(2 * N + 1) {
		for (int i = 1; i <= 2 * N; ++i) {
			par[i] = N + (i - 1) % N + 1;
			sm[i] = par[i] - N;
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
		sm[x] += sm[y];
		return true;
	}
	bool move(int x, int y) {
		if (same(x, y)) {
			return false;
		}
		y = root(y);
		--sz[root(x)];
		sm[root(x)] -= x;
		par[x] = y;
		++sz[y];
		sm[y] += x;
		return true;
	}
	int size(int x) {
		return sz[root(x)];
	}
	ll sum(int x) {
		return sm[root(x)];
	}
private:
	vector<int> par, sz;
	vector<ll> sm;
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, M{};
	while (cin >> N >> M) {
		UF uf(N);
		while (M--) {
			int op{}, p{}, q{};
			cin >> op;
			if (op == 1) {
				cin >> p >> q;
				uf.unite(p, q);
			} else if (op == 2) {
				cin >> p >> q;
				uf.move(p, q);
			} else {
				cin >> p;
				cout << uf.size(p) << " " << uf.sum(p) << "\n";
			}
		}
	}
	return 0;
}
