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
	int N{};
	cin >> N;
	vector<vector<int>> A(N, vector<int>(N));
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			cin >> A[i][j];
		}
	}
	vector<vector<ii>> B(201);
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			B[A[i][j]].push_back({i, j});
		}
	}
	int ans = 1e9;
	for (int i = 0; i < 201; ++i) {
		UF uf(N * N);
		for (int j = i; j < 201; ++j) {
			for (auto &[x, y] : B[j]) {
				for (int k = 0; k < 4; ++k) {
					int nx = x + dx[k];
					int ny = y + dy[k];
					if (0 <= nx && nx < N && 0 <= ny && ny < N && i <= A[nx][ny] && A[nx][ny] <= j) {
						uf.unite(x * N + y, nx * N + ny);
					}
				}
			}
			if (uf.same(0, N * N - 1)) {
				ans = min(ans, j - i);
				break;
			}
		}
	}
	cout << ans << "\n";
	return 0;
}
