#include <bits/stdc++.h>

using namespace std;

using ii = pair<int, int>;

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

void solve(int N, vector<ii> &A) {
	UF uf(N + 1);
	for (int i = A.size() - 1; i >= 0; --i) {
		auto &[u, v] = A[i];
		if (!uf.unite(u, v)) {
			A.erase(A.begin() + i);
			break;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, M{}, K{};
	cin >> N >> M >> K;
	UF uf1(N + 1);
	UF uf2(N + 1);
	vector<ii> R, B;
	while (M--) {
		char c{};
		int u{}, v{};
		cin >> c >> u >> v;
		if (c == 'R' && uf1.unite(u, v)) {
			R.push_back({u, v});
		} else if (c == 'B' && uf2.unite(u, v)) {
			B.push_back({u, v});
		}
	}
	if (K < N - R.size() - 1 || K > B.size()) {
		cout << "0\n";
		return 0;
	}
	for (int i = 0; i < B.size(); ++i) {
		auto &[u, v] = B[i];
		if (uf1.unite(u, v)) {
			R.push_back({u, v});
			B.erase(B.begin() + i--);
			--K;
		}
	}
	for (int i = 0; i < K; ++i) {
		R.push_back(B[i]);
		solve(N, R);
	}
	for (auto &[u, v] : R) {
		cout << u << " " << v << "\n";
	}
	return 0;
}
