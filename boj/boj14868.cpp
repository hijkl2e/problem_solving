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
	int N{}, K{};
	cin >> N >> K;
	vector<vector<int>> D(N, vector<int>(N, -1));
	queue<ii> q;
	while (K--) {
		int x{}, y{};
		cin >> x >> y;
		--x, --y;
		D[x][y] = 0;
		q.push({x, y});
	}
	UF uf(N * N);
	int ans{};
	while (q.size()) {
		auto [x, y] = q.front(); q.pop();
		for (int i = 0; i < 4; ++i) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (0 <= nx && nx < N && 0 <= ny && ny < N && D[nx][ny] <= D[x][y]
					&& uf.unite(x * N + y, nx * N + ny)) {
				if (D[nx][ny] == -1) {
					D[nx][ny] = D[x][y] + 1;
					q.push({nx, ny});
				} else {
					ans = max(ans, D[x][y]);
				}
			}
		}
	}
	cout << ans << "\n";
	return 0;
}
