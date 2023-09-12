#include <bits/stdc++.h>

using namespace std;

using ii = pair<int, int>;

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
	vector<vector<int>> A(N + 2, vector<int>(M + 2));
	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= M; ++j) {
			cin >> A[i][j];
		}
	}
	N += 2, M += 2;
	vector<vector<ii>> B(10001);
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			B[A[i][j]].push_back({i, j});
		}
	}
	UF uf(N * M);
	int ans{}, cnt{};
	for (int k = 0; k < B.size(); ++k) {
		for (auto &[x, y] : B[k]) {
			for (int i = 0; i < 4; ++i) {
				int nx = x + dx[i];
				int ny = y + dy[i];
				if (0 <= nx && nx < N && 0 <= ny && ny < M && A[nx][ny] <= k) {
					uf.unite(x * M + y, nx * M + ny);
				}
			}
		}
		cnt += B[k].size();
		ans += cnt - uf.size(0);
	}
	cout << ans << "\n";
	return 0;
}
