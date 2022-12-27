#include <bits/stdc++.h>

using namespace std;

using ii = pair<int, int>;

const int dx[4]{0, 0, -1, 1};
const int dy[4]{-1, 1, 0, 0};

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
	int N{}, M{}, K{};
	cin >> N >> M >> K;
	vector<vector<int>> D(N, vector<int>(M));
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			char c{};
			cin >> c;
			D[i][j] = c == 'L' ? 0 : c == 'R' ? 1 : c == 'U' ? 2 : 3;
		}
	}
	vector<vector<int>> L(N, vector<int>(M));
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			cin >> L[i][j];
		}
	}
	UF uf(N * M);
	vector<ii> A;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			int nx = i + dx[D[i][j]] * L[i][j];
			int ny = j + dy[D[i][j]] * L[i][j];
			if (0 <= nx && nx < N && 0 <= ny && ny < M) {
				uf.unite(i * M + j, nx * M + ny);
			} else {
				A.push_back({i, j});
			}
		}
	}
	vector<int> B;
	for (auto &[x, y] : A) {
		B.push_back(uf.size(x * M + y));
	}
	sort(B.rbegin(), B.rend());
	ii ans;
	ans.first = ans.second = accumulate(B.begin(), B.end(), 0);
	ans.first -= accumulate(B.begin(), B.begin() + min<int>(K, B.size()), 0);
	B.clear();
	deque<bool> C(N * M, true);
	for (auto &[x, y] : A) {
		C[uf.root(x * M + y)] = false;
	}
	for (int i = 0; i < N * M; ++i) {
		if (uf.root(i) == i && C[i]) {
			B.push_back(uf.size(i));
		}
	}
	sort(B.rbegin(), B.rend());
	ans.second += accumulate(B.begin(), B.begin() + min<int>(K, B.size()), 0);
	cout << ans.first << " " << ans.second << "\n";
	return 0;
}
