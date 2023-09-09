#include <bits/stdc++.h>

using namespace std;

const int dx[4]{1, -1, 0, 0};
const int dy[4]{0, 0, 1, -1};

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

int solve(int x1, int y1, int x2, int y2) {
	for (int i = 0; i < 4; ++i) {
		int nx = x1 + dx[i];
		int ny = y1 + dy[i];
		if (nx == x2 && ny == y2) {
			return i;
		}
	}
	return -1;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, K{}, R{};
	cin >> N >> K >> R;
	vector<deque<bool>> G(N * N, deque<bool>(4));
	while (R--) {
		int x1{}, y1{}, x2{}, y2{};
		cin >> x1 >> y1 >> x2 >> y2;
		--x1, --y1, --x2, --y2;
		int d1 = solve(x1, y1, x2, y2);
		int d2 = solve(x2, y2, x1, y1);
		G[x1 * N + y1][d1] = G[x2 * N + y2][d2] = true;
	}
	UF uf(N * N);
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			for (int k = 0; k < 4; ++k) {
				if (G[i * N + j][k]) {
					continue;
				}
				int nx = i + dx[k];
				int ny = j + dy[k];
				if (0 <= nx && nx < N && 0 <= ny && ny < N) {
					uf.unite(i * N + j, nx * N + ny);
				}
			}
		}
	}
	vector<int> A(N * N);
	for (int i = 0; i < K; ++i) {
		int x{}, y{};
		cin >> x >> y;
		--x, --y;
		++A[uf.root(x * N + y)];
	}
	int ans{};
	for (int i = 0; i < A.size(); ++i) {
		ans += A[i] * (K - A[i]);
	}
	ans /= 2;
	cout << ans << "\n";
	return 0;
}
