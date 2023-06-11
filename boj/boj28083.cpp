#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using iii = tuple<int, int, int>;

const int dx[4]{1, -1, 0, 0};
const int dy[4]{0, 0, 1, -1};

class UF {
public:
	UF(int N) : par(N), sz(N, 1), v(N) {
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
		v[x] += v[y];
		return true;
	}
	int size(int x) {
		return sz[root(x)];
	}
	ll &val(int x) {
		return v[root(x)];
	}
private:
	vector<int> par, sz;
	vector<ll> v;
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
			cin >> uf.val(i * M + j);
		}
	}
	vector<iii> B(N * M);
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			B[i * M + j] = {A[i][j], i, j};
		}
	}
	sort(B.begin(), B.end());
	vector<vector<ll>> C(N, vector<ll>(M));
	for (int i = 0, j = 1; i < B.size(); i = j++) {
		while (j < B.size()) {
			if (get<0>(B[i]) == get<0>(B[j])) {
				++j;
			} else {
				break;
			}
		}
		for (int k = i; k < j; ++k) {
			auto &[h, x, y] = B[k];
			for (int l = 0; l < 4; ++l) {
				int nx = x + dx[l];
				int ny = y + dy[l];
				if (0 <= nx && nx < N && 0 <= ny && ny < M && A[nx][ny] <= h) {
					uf.unite(x * M + y, nx * M + ny);
				}
			}
		}
		for (int k = i; k < j; ++k) {
			auto &[h, x, y] = B[k];
			C[x][y] = uf.val(x * M + y);
		}
	}
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			cout << C[i][j] << (j == M - 1 ? "\n" : " ");
		}
	}
	return 0;
}
