#include <bits/stdc++.h>

using namespace std;

using edge = tuple<double, int, int>;

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
	for (int tc = 0; tc < T; ++tc) {
		int N{};
		cin >> N;
		vector<double> x(N);
		vector<double> y(N);
		for (int i = 0; i < N; ++i) {
			cin >> x[i] >> y[i];
		}
		vector<edge> E;
		for (int i = 0; i < N; ++i) {
			for (int j = i + 1; j < N; ++j) {
				E.push_back({sqrt((x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j])), i, j});
			}
		}
		sort(E.begin(), E.end());
		UF uf(N);
		double ans{};
		for (auto &[w, u, v] : E) {
			if (uf.unite(u, v)) {
				ans += w;
			}
		}
		if (tc) {
			cout << "\n";
		}
		cout << fixed << setprecision(2);
		cout << ans << "\n";
	}
	return 0;
}
