#include <bits/stdc++.h>

using namespace std;

using ii = pair<int, int>;
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

int N;
vector<string> A;
vector<ii> B;

vector<int> solve(int sx, int sy) {
	static vector<vector<int>> D;
	D.assign(N, vector<int>(N, -1));
	queue<ii> q;
	D[sx][sy] = 0;
	q.push({sx, sy});
	while (q.size()) {
		auto [x, y] = q.front(); q.pop();
		for (int i = 0; i < 4; ++i) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (A[nx][ny] != '1' && D[nx][ny] == -1) {
				D[nx][ny] = D[x][y] + 1;
				q.push({nx, ny});
			}
		}
	}
	vector<int> E;
	for (auto &[x, y] : B) {
		E.push_back(D[x][y]);
	}
	return E;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int M{};
	cin >> N >> M;
	cin.ignore();
	A.resize(N);
	for (int i = 0; i < N; ++i) {
		getline(cin, A[i]);
	}
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			if (A[i][j] == 'S' || A[i][j] == 'K') {
				B.push_back({i, j});
			}
		}
	}
	vector<vector<int>> C;
	for (auto &[x, y] : B) {
		C.push_back(solve(x, y));
	}
	vector<edge> E;
	for (int i = 0; i <= M; ++i) {
		for (int j = i + 1; j <= M; ++j) {
			E.push_back({C[i][j], i, j});
		}
	}
	sort(E.begin(), E.end());
	if (get<0>(E[0]) == -1) {
		cout << "-1\n";
		return 0;
	}
	UF uf(M + 1);
	int ans{};
	for (auto &[w, u, v] : E) {
		if (uf.unite(u, v)) {
			ans += w;
		}
	}
	cout << ans << "\n";
	return 0;
}
