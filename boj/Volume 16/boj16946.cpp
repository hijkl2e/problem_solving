#include <bits/stdc++.h>

using namespace std;

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

const int dx[4]{1, -1, 0, 0};
const int dy[4]{0, 0, 1, -1};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, M{};
	cin >> N >> M;
	cin.ignore();
	vector<string> A(N);
	for (int i = 0; i < N; ++i) {
		getline(cin, A[i]);
	}
	UF uf(N * M);
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			if (A[i][j] == '1') {
				continue;
			}
			if (i + 1 < N && A[i + 1][j] == '0') {
				uf.unite(i * M + j, (i + 1) * M + j);
			}
			if (j + 1 < M && A[i][j + 1] == '0') {
				uf.unite(i * M + j, i * M + j + 1);
			}
		}
	}
	vector<vector<int>> B(N, vector<int>(M));
	set<int> S;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			if (A[i][j] == '0') {
				continue;
			}
			S.clear();
			int cnt = 1;
			for (int k = 0; k < 4; ++k) {
				int nx = i + dx[k];
				int ny = j + dy[k];
				if (0 <= nx && nx < N && 0 <= ny && ny < M && A[nx][ny] == '0'
						&& S.insert(uf.root(nx * M + ny)).second) {
					cnt += uf.size(nx * M + ny);
				}
			}
			B[i][j] = cnt % 10;
		}
	}
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			cout << B[i][j];
		}
		cout << "\n";
	}
	return 0;
}
