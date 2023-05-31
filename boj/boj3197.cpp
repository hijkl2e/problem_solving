#include <bits/stdc++.h>

using namespace std;

using ii = pair<int, int>;
using iii = tuple<int, int, int>;

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
	int R{}, C{};
	cin >> R >> C;
	cin.ignore();
	vector<string> A(R);
	for (int i = 0; i < R; ++i) {
		getline(cin, A[i]);
	}
	vector<vector<int>> D(R, vector<int>(C, -1));
	queue<ii> q;
	int lx1{}, ly1{}, lx2{}, ly2{};
	for (int i = 0; i < R; ++i) {
		for (int j = 0; j < C; ++j) {
			if (A[i][j] == 'X') {
				continue;
			}
			D[i][j] = 0;
			q.push({i, j});
			if (A[i][j] == 'L') {
				lx1 = i, ly1 = j;
				swap(lx1, lx2);
				swap(ly1, ly2);
			}
		}
	}
	while (q.size()) {
		auto [x, y] = q.front(); q.pop();
		for (int i = 0; i < 4; ++i) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (0 <= nx && nx < R && 0 <= ny && ny < C && D[nx][ny] == -1) {
				D[nx][ny] = D[x][y] + 1;
				q.push({nx, ny});
			}
		}
	}
	vector<iii> B(R * C);
	for (int i = 0; i < R; ++i) {
		for (int j = 0; j < C; ++j) {
			B[i * C + j] = {D[i][j], i, j};
		}
	}
	sort(B.begin(), B.end());
	UF uf(R * C);
	int ans{};
	for (auto &[d, x, y] : B) {
		for (int i = 0; i < 4; ++i) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (0 <= nx && nx < R && 0 <= ny && ny < C && D[nx][ny] <= D[x][y]) {
				uf.unite(x * C + y, nx * C + ny);
			}
		}
		if (uf.same(lx1 * C + ly1, lx2 * C + ly2)) {
			ans = d;
			break;
		}
	}
	cout << ans << "\n";
	return 0;
}
