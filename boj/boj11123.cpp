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

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T{};
	cin >> T;
	while (T--) {
		int R{}, C{};
		cin >> R >> C;
		cin.ignore();
		vector<string> A(R);
		for (int i = 0; i < R; ++i) {
			getline(cin, A[i]);
		}
		UF uf(R * C);
		for (int i = 0; i < R; ++i) {
			for (int j = 0; j < C; ++j) {
				if (A[i][j] == '.') {
					continue;
				}
				for (int k = 0; k < 4; ++k) {
					int nx = i + dx[k];
					int ny = j + dy[k];
					if (0 <= nx && nx < R && 0 <= ny && ny < C && A[nx][ny] == '#') {
						uf.unite(i * C + j, nx * C + ny);
					}
				}
			}
		}
		int ans{};
		for (int i = 0; i < R; ++i) {
			for (int j = 0; j < C; ++j) {
				if (A[i][j] == '#' && uf.root(i * C + j) == i * C + j) {
					++ans;
				}
			}
		}
		cout << ans << "\n";
	}
	return 0;
}
