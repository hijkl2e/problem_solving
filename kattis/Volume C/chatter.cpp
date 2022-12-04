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
	int N{}, r{}, a{}, b{}, c{};
	while (cin >> N >> r >> a >> b >> c) {
		UF uf(N);
		for (int i = 0; i < N; ++i) {
			int x{}, y{};
			while (x == y) {
				r = (r * a + b) % c;
				x = r % N;
				r = (r * a + b) % c;
				y = r % N;
			}
			uf.unite(x, y);
		}
		map<int, int> freq;
		int cnt{};
		for (int i = 0; i < N; ++i) {
			if (uf.root(i) == i) {
				++freq[-uf.size(i)];
				++cnt;
			}
		}
		cout << cnt;
		for (auto &[u, v] : freq) {
			cout << " " << -u;
			if (v > 1) {
				cout << "x" << v;
			}
		}
		cout << "\n";
	}
	return 0;
}
