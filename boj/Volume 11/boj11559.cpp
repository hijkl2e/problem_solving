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
	vector<string> A(12);
	for (int i = 0; i < 12; ++i) {
		getline(cin, A[i]);
	}
	int ans{};
	while (true) {
		UF uf(72);
		for (int i = 0; i < 12; ++i) {
			for (int j = 0; j < 6; ++j) {
				if (A[i][j] == '.') {
					continue;
				}
				if (i < 11 && A[i][j] == A[i + 1][j]) {
					uf.unite(6 * i + j, 6 * (i + 1) + j);
				}
				if (j < 5 && A[i][j] == A[i][j + 1]) {
					uf.unite(6 * i + j, 6 * i + j + 1);
				}
			}
		}
		bool flag = true;
		for (int i = 0; i < 12; ++i) {
			for (int j = 0; j < 6; ++j) {
				if (uf.size(6 * i + j) > 3) {
					A[i][j] = '.';
					flag = false;
				}
			}
		}
		if (flag) {
			break;
		}
		for (int j = 0; j < 6; ++j) {
			int k = 11;
			for (int i = 11; i >= 0; --i) {
				if (A[i][j] == '.') {
					continue;
				}
				A[k--][j] = A[i][j];
			}
			for (int i = k; i >= 0; --i) {
				A[i][j] = '.';
			}
		}
		++ans;
	}
	cout << ans << "\n";
	return 0;
}
