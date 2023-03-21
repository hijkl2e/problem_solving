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
	int N{}, L{}, R{};
	cin >> N >> L >> R;
	vector<vector<int>> A(N, vector<int>(N));
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			cin >> A[i][j];
		}
	}
	vector<int> B(N * N);
	int ans = -1;
	bool flag = true;
	while (flag) {
		++ans;
		flag = false;
		UF uf(N * N);
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < N; ++j) {
				if (i + 1 < N) {
					int d = abs(A[i][j] - A[i + 1][j]);
					if (L <= d && d <= R) {
						uf.unite(i * N + j, (i + 1) * N + j);
						flag = true;
					}
				}
				if (j + 1 < N) {
					int d = abs(A[i][j] - A[i][j + 1]);
					if (L <= d && d <= R) {
						uf.unite(i * N + j, i * N + j + 1);
						flag = true;
					}
				}
			}
		}
		fill(B.begin(), B.end(), 0);
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < N; ++j) {
				B[uf.root(i * N + j)] += A[i][j];
			}
		}
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < N; ++j) {
				int x = i * N + j;
				A[i][j] = B[uf.root(x)] / uf.size(x);
			}
		}
	}
	cout << ans << "\n";
	return 0;
}
