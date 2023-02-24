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

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, M{}, K{};
	cin >> N >> M >> K;
	deque<bool> A(N + 1);
	while (K--) {
		int x{};
		cin >> x;
		A[x] = true;
	}
	vector<vector<int>> B(M);
	for (int i = 0; i < M; ++i) {
		cin >> K;
		B[i].resize(K);
		for (int j = 0; j < K; ++j) {
			cin >> B[i][j];
		}
	}
	UF uf(N + 1);
	for (int i = 0; i < M; ++i) {
		for (int j = 1; j < B[i].size(); ++j) {
			uf.unite(B[i][j - 1], B[i][j]);
		}
	}
	for (int i = 1; i <= N; ++i) {
		if (A[i]) {
			A[uf.root(i)] = true;
		}
	}
	int ans{};
	for (int i = 0; i < M; ++i) {
		bool flag = true;
		for (int j = 0; j < B[i].size(); ++j) {
			if (A[uf.root(B[i][j])]) {
				flag = false;
				break;
			}
		}
		if (flag) {
			++ans;
		}
	}
	cout << ans << "\n";
	return 0;
}
