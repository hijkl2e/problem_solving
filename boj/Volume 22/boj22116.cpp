#include <bits/stdc++.h>

using namespace std;

using edge = tuple<int, int, int>;

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
	vector<edge> E;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			if (i < N - 1) {
				E.push_back({abs(A[i][j] - A[i + 1][j]), i * N + j, (i + 1) * N + j});
			}
			if (j < N - 1) {
				E.push_back({abs(A[i][j] - A[i][j + 1]), i * N + j, i * N + j + 1});
			}
		}
	}
	sort(E.begin(), E.end());
	UF uf(N * N);
	int ans{};
	for (auto &[w, u, v] : E) {
		uf.unite(u, v);
		if (uf.same(0, N * N - 1)) {
			ans = w;
			break;
		}
	}
	cout << ans << "\n";
	return 0;
}
