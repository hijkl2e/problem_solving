#include <bits/stdc++.h>

using namespace std;

using ii = pair<int, int>;

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

int N;
vector<vector<int>> A, B;
vector<string> grid;

int c2i(int x, int y) {
	return x * N + y;
}

void rotate(vector<ii> &v, bool flag) {
	for (auto &p : v) {
		p = {p.second, flag ? p.first : (N - p.first - 1)};
	}
}

bool compare(vector<ii> &w, vector<ii> &g) {
	if (w.empty()) {
		return true;
	}
	sort(w.begin(), w.end());
	sort(g.begin(), g.end());
	for (int k = 0; k < 8; ++k) {
		bool flag = true;
		ii d = {w[0].first - g[0].first, w[0].second - g[0].second};
		for (int i = 0; i < w.size(); ++i) {
			flag &= make_pair(w[i].first - g[i].first, w[i].second - g[i].second) == d;
		}
		if (flag) {
			return true;
		}
		rotate(g, k % 4 == 3);
		sort(g.begin(), g.end());
	}
	return false;
}

bool solve() {
	UF uf1(N * N);
	UF uf2(N * N);
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			if (i < N - 1 && grid[2 * i + 2][2 * j + 1] == '.') {
				uf1.unite(c2i(i, j), c2i(i + 1, j));
				if (A[i][j] == A[i + 1][j]) {
					uf2.unite(c2i(i, j), c2i(i + 1, j));
				}
			}
			if (j < N - 1 && grid[2 * i + 1][2 * j + 2] == '.') {
				uf1.unite(c2i(i, j), c2i(i, j + 1));
				if (A[i][j] == A[i][j + 1]) {
					uf2.unite(c2i(i, j), c2i(i, j + 1));
				}
			}
		}
	}
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			if ((i < N - 1 && grid[2 * i + 2][2 * j + 1] == '-'
					&& uf1.same(c2i(i, j), c2i(i + 1, j)))
					|| (j < N - 1 && grid[2 * i + 1][2 * j + 2] == '|'
					&& uf1.same(c2i(i, j), c2i(i, j + 1)))) {
				return false;
			}
		}
	}
	vector<vector<ii>> w(N * N);
	vector<vector<ii>> g(N * N);
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			int x = uf1.root(c2i(i, j));
			if (A[i][j]) {
				g[x].push_back({i, j});
			} else {
				w[x].push_back({i, j});
			}
		}
	}
	for (int i = 0; i < N * N; ++i) {
		if (w[i].size() != g[i].size()) {
			return false;
		}
		int num{};
		for (auto &v : {w[i], g[i]}) {
			for (auto &[x, y] : v) {
				if (!uf2.same(c2i(v[0].first, v[0].second), c2i(x, y))) {
					return false;
				}
				if (B[x][y]) {
					num = num == 0 ? B[x][y] : -1;
				}
			}
		}
		if (num == -1 || (num && w[i].size() != num) || !compare(w[i], g[i])) {
			return false;
		}
	}
	return true;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> N;
	A.assign(N, vector<int>(N));
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			cin >> A[i][j];
		}
	}
	B.assign(N, vector<int>(N));
	int K{};
	cin >> K;
	while (K--) {
		int r{}, c{}, k{};
		cin >> r >> c >> k;
		B[r - 1][c - 1] = k;
	}
	grid.resize(2 * N + 1);
	for (int i = 0; i < 2 * N + 1; ++i) {
		cin >> grid[i];
	}
	cout << solve() << "\n";
	return 0;
}
