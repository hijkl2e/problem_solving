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
	int M{}, N{};
	cin >> M >> N;
	vector<vector<int>> A(N, vector<int>(M));
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			cin >> A[i][j];
		}
	}
	UF uf(N * M);
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			if (j < M - 1 && (A[i][j] & 4) == 0) {
				uf.unite(i * M + j, i * M + j + 1);
			}
			if (i < N - 1 && (A[i][j] & 8) == 0) {
				uf.unite(i * M + j, (i + 1) * M + j);
			}
		}
	}
	int ans{};
	for (int i = 0; i < N * M; ++i) {
		if (uf.root(i) == i) {
			++ans;
		}
	}
	cout << ans << "\n";
	ans = 0;
	for (int i = 0; i < N * M; ++i) {
		ans = max(ans, uf.size(i));
	}
	cout << ans << "\n";
	ans = 0;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			if (j < M - 1 && !uf.same(i * M + j, i * M + j + 1)) {
				ans = max(ans, uf.size(i * M + j) + uf.size(i * M + j + 1));
			}
			if (i < N - 1 && !uf.same(i * M + j, (i + 1) * M + j)) {
				ans = max(ans, uf.size(i * M + j) + uf.size((i + 1) * M + j));
			}
		}
	}
	cout << ans << "\n";
	return 0;
}
