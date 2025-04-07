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
	int N{}, M{};
	cin >> N >> M;
	vector<vector<int>> A(N, vector<int>(M));
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			cin >> A[i][j];
		}
	}
	UF uf(N * M);
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			if (A[i][j] == 0) {
				continue;
			}
			for (int k = 0; k < 4; ++k) {
				int nx = i + dx[k];
				int ny = j + dy[k];
				if (0 <= nx && nx < N && 0 <= ny && ny < M && A[nx][ny]) {
					uf.unite(i * M + j, nx * M + ny);
				}
			}
		}
	}
	set<int> S;
	int ans{};
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			if (A[i][j]) {
				continue;
			}
			S.clear();
			for (int k = 0; k < 4; ++k) {
				int nx = i + dx[k];
				int ny = j + dy[k];
				if (0 <= nx && nx < N && 0 <= ny && ny < M && A[nx][ny]) {
					S.insert(uf.root(nx * M + ny));
				}
			}
			int cnt = 1;
			for (int x : S) {
				cnt += uf.size(x);
			}
			ans = max(ans, cnt);
		}
	}
	cout << ans << "\n";
	return 0;
}
