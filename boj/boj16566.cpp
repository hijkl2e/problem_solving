#include <bits/stdc++.h>

using namespace std;

class UF {
public:
	UF(int N) : par(N), sz(N, 1), nxt(N) {
		for (int i = 0; i < N; ++i) {
			par[i] = nxt[i] = i;
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
		nxt[x] = max(nxt[x], nxt[y]);
		return true;
	}
	int size(int x) {
		return sz[root(x)];
	}
	int next(int x) {
		return nxt[root(x)];
	}
private:
	vector<int> par, sz, nxt;
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, M{}, K{};
	cin >> N >> M >> K;
	vector<int> A(M);
	for (int i = 0; i < M; ++i) {
		cin >> A[i];
	}
	sort(A.begin(), A.end());
	UF uf(M + 1);
	while (K--) {
		int x{};
		cin >> x;
		int y = upper_bound(A.begin(), A.end(), x) - A.begin();
		int z = uf.next(y);
		cout << A[z] << "\n";
		uf.unite(z, z + 1);
	}
	return 0;
}
