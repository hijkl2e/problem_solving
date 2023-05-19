#include <bits/stdc++.h>

using namespace std;

const int dx[4]{-1, 0, 0, 1};
const int dy[4]{0, -1, 1, 0};

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
	int T{};
	cin >> T;
	for (int tc = 1; tc <= T; ++tc) {
		int R{}, C{};
		cin >> R >> C;
		vector<vector<int>> A(R, vector<int>(C));
		for (int i = 0; i < R; ++i) {
			for (int j = 0; j < C; ++j) {
				cin >> A[i][j];
			}
		}
		UF uf(R * C);
		for (int i = 0; i < R; ++i) {
			for (int j = 0; j < C; ++j) {
				int p = -1, v = A[i][j];
				for (int k = 0; k < 4; ++k) {
					int nx = i + dx[k];
					int ny = j + dy[k];
					if (0 <= nx && nx < R && 0 <= ny && ny < C && v > A[nx][ny]) {
						p = k, v = A[nx][ny];
					}
				}
				if (p != -1) {
					int nx = i + dx[p];
					int ny = j + dy[p];
					uf.unite(i * C + j, nx * C + ny);
				}
			}
		}
		vector<int> B(R * C, -1);
		int p{};
		for (int i = 0; i < R; ++i) {
			for (int j = 0; j < C; ++j) {
				int r = uf.root(i * C + j);
				if (B[r] == -1) {
					B[r] = p++;
				}
			}
		}
		cout << "Case #" << tc << ":\n";
		for (int i = 0; i < R; ++i) {
			for (int j = 0; j < C; ++j) {
				char c = 'a' + B[uf.root(i * C + j)];
				cout << c << (j == C - 1 ? "\n" : " ");
			}
		}
	}
	return 0;
}
