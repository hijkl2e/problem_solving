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
	while (T--) {
		int N{};
		cin >> N;
		vector<int> x(N);
		vector<int> y(N);
		vector<int> r(N);
		for (int i = 0; i < N; ++i) {
			cin >> x[i] >> y[i] >> r[i];
		}
		UF uf(N);
		for (int i = 0; i < N; ++i) {
			for (int j = i + 1; j < N; ++j) {
				int d = (x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]);
				if (d <= (r[i] + r[j]) * (r[i] + r[j])) {
					uf.unite(i, j);
				}
			}
		}
		int ans{};
		for (int i = 0; i < N; ++i) {
			if (uf.root(i) == i) {
				++ans;
			}
		}
		cout << ans << "\n";
	}
	return 0;
}
