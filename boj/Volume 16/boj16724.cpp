#include <bits/stdc++.h>

using namespace std;

const int dx[4]{-1, 1, 0, 0};
const int dy[4]{0, 0, -1, 1};

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
	cin.ignore();
	vector<string> A(N);
	for (int i = 0; i < N; ++i) {
		getline(cin, A[i]);
	}
	map<char, int> d2i{
		{'U', 0}, {'D', 1}, {'L', 2}, {'R', 3}
	};
	UF uf(N * M);
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			int d = d2i[A[i][j]];
			int nx = i + dx[d];
			int ny = j + dy[d];
			uf.unite(i * M + j, nx * M + ny);
		}
	}
	int ans{};
	for (int i = 0; i < N * M; ++i) {
		if (uf.root(i) == i) {
			++ans;
		}
	}
	cout << ans << "\n";
	return 0;
}
