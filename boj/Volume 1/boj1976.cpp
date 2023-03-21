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
	int N{}, M{};
	cin >> N >> M;
	UF uf(N + 1);
	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= N; ++j) {
			int x{};
			cin >> x;
			if (x) {
				uf.unite(i, j);
			}
		}
	}
	vector<int> A(M);
	for (int i = 0; i < M; ++i) {
		cin >> A[i];
	}
	bool yes = true;
	for (int i = 0; i < M - 1; ++i) {
		yes &= uf.same(A[i], A[i + 1]);
	}
	cout << (yes ? "YES" : "NO") << "\n";
	return 0;
}
