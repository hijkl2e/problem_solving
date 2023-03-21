#include <bits/stdc++.h>

using namespace std;

using edge = tuple<int, int, int>;

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

int N, M;
vector<vector<int>> A, B;

void dfs(int x, int y, int c) {
	B[x][y] = c;
	for (int i = 0; i < 4; ++i) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (0 <= nx && nx < N && 0 <= ny && ny < M && A[nx][ny] && B[nx][ny] == -1) {
			B[nx][ny] = c;
			dfs(nx, ny, c);
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> N >> M;
	A.assign(N, vector<int>(M));
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			cin >> A[i][j];
		}
	}
	B.assign(N, vector<int>(M, -1));
	int cnt{};
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			if (A[i][j] && B[i][j] == -1) {
				dfs(i, j, cnt++);
			}
		}
	}
	vector<edge> E;
	for (int i = 0; i < N; ++i) {
		for (int j = 0, k = -1; j < M; ++j) {
			if (A[i][j] == 0) {
				continue;
			} else if (k != -1 && B[i][j] != B[i][k] && j - k > 2) {
				E.push_back({j - k - 1, B[i][j], B[i][k]});
			}
			k = j;
		}
	}
	for (int j = 0; j < M; ++j) {
		for (int i = 0, k = -1; i < N; ++i) {
			if (A[i][j] == 0) {
				continue;
			} else if (k != -1 && B[i][j] != B[k][j] && i - k > 2) {
				E.push_back({i - k - 1, B[i][j], B[k][j]});
			}
			k = i;
		}
	}
	sort(E.begin(), E.end());
	UF uf(cnt);
	int ans{};
	for (auto &[w, u, v] : E) {
		if (uf.unite(u, v)) {
			ans += w;
			--cnt;
		}
	}
	cout << (cnt == 1 ? ans : -1) << "\n";
	return 0;
}
