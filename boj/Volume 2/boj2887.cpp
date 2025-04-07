#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using rec = tuple<int, int, int, int>;
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
	int N{};
	cin >> N;
	vector<rec> A(N);
	for (int i = 0; i < N; ++i) {
		auto &[x, y, z, k] = A[i];
		cin >> x >> y >> z;
		k = i;
	}
	vector<edge> E;
	for (int i = 0; i < 3; ++i) {
		sort(A.begin(), A.end());
		for (int j = 0; j < N - 1; ++j) {
			auto &[x1, y1, z1, k1] = A[j];
			auto &[x2, y2, z2, k2] = A[j + 1];
			E.push_back({x2 - x1, k1, k2});
		}
		for (auto &[x, y, z, k] : A) {
			swap(x, i ? z : y);
		}
	}
	sort(E.begin(), E.end());
	UF uf(N);
	ll ans{};
	for (auto &[w, u, v] : E) {
		if (uf.unite(u, v)) {
			ans += w;
		}
	}
	cout << ans << "\n";
	return 0;
}
