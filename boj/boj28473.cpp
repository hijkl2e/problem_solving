#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using edge = tuple<int, int, int, int>;

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
	vector<edge> E(M);
	for (auto &[z, w, x, y] : E) {
		cin >> x >> y >> z >> w;
	}
	sort(E.begin(), E.end());
	UF uf(N + 1);
	string S;
	ll c{};
	for (auto &[z, w, x, y] : E) {
		if (uf.unite(x, y)) {
			S += to_string(z);
			c += w;
		}
	}
	if (S.size() == N - 1) {
		cout << S << " " << c << "\n";
	} else {
		cout << "-1\n";
	}
	return 0;
}
