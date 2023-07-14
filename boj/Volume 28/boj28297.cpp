#include <bits/stdc++.h>

using namespace std;

using edge = tuple<double, int, int>;

const double PI = acos(-1);

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

int square(int x) {
	return x * x;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	vector<int> x(N);
	vector<int> y(N);
	vector<int> r(N);
	for (int i = 0; i < N; ++i) {
		cin >> x[i] >> y[i] >> r[i];
	}
	UF uf(N);
	vector<edge> E;
	for (int i = 0; i < N; ++i) {
		for (int j = i + 1; j < N; ++j) {
			int d = square(x[i] - x[j]) + square(y[i] - y[j]);
			if (d <= square(r[i] + r[j])) {
				uf.unite(i, j);
				continue;
			}
			double l = sqrt(d - square(r[i] - r[j]));
			double b = asin(l / sqrt(d));
			E.push_back({2 * (l + max(r[i], r[j]) * PI - abs(r[i] - r[j]) * b), i, j});
		}
	}
	sort(E.begin(), E.end());
	double ans{};
	for (auto &[w, u, v] : E) {
		if (uf.unite(u, v)) {
			ans += w;
		}
	}
	cout << fixed << setprecision(10);
	cout << ans << "\n";
	return 0;
}
