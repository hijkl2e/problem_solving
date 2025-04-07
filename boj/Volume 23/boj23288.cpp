#include <bits/stdc++.h>

using namespace std;

const int dx[4]{0, 1, 0, -1};
const int dy[4]{1, 0, -1, 0};
const int dz[4][6]{
	{3, 1, 0, 5, 4, 2}, {1, 5, 2, 3, 0, 4},
	{2, 1, 5, 0, 4, 3}, {4, 0, 2, 3, 5, 1}
};

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

void solve(vector<int> &A, int d) {
	static vector<int> B(6);
	for (int i = 0; i < 6; ++i) {
		B[i] = A[dz[d][i]];
	}
	swap(A, B);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, M{}, K{};
	cin >> N >> M >> K;
	vector<vector<int>> A(N + 1, vector<int>(M + 1));
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			cin >> A[i][j];
		}
	}
	UF uf(N * M);
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			if (A[i][j] == A[i + 1][j]) {
				uf.unite(i * M + j, (i + 1) * M + j);
			}
			if (A[i][j] == A[i][j + 1]) {
				uf.unite(i * M + j, i * M + j + 1);
			}
		}
	}
	vector<int> B(6);
	for (int i = 0; i < 6; ++i) {
		B[i] = i + 1;
	}
	int ans{}, x{}, y{}, d{};
	while (K--) {
		x += dx[d];
		y += dy[d];
		if (x == -1 || x == N || y == -1 || y == M) {
			d ^= 2;
			x += 2 * dx[d];
			y += 2 * dy[d];
		}
		solve(B, d);
		ans += A[x][y] * uf.size(x * M + y);
		d = (d + (B[5] > A[x][y] ? 1 : B[5] < A[x][y] ? 3 : 0)) % 4;
	}
	cout << ans << "\n";
	return 0;
}
