#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9 + 7;

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
	vector<int> A(N + 1);
	for (int i = 1; i <= N; ++i) {
		cin >> A[i];
	}
	vector<vector<int>> G(N + 1);
	for (int i = 1; i <= N; ++i) {
		int K{};
		cin >> K;
		while (K--) {
			int x{};
			cin >> x;
			G[i].push_back(x);
		}
	}
	int ans = INF;
	for (int i = 1; i < (1 << N) - 1; i += 2) {
		UF uf(N + 1);
		for (int j = 1; j <= N; ++j) {
			for (int x : G[j]) {
				if ((((i >> (j - 1)) ^ (i >> (x - 1))) & 1) == 0) {
					uf.unite(j, x);
				}
			}
		}
		bool flag{};
		for (int j = 1; j <= N; ++j) {
			for (int k = j + 1; k <= N; ++k) {
				if (((((i >> (j - 1)) ^ (i >> (k - 1))) & 1) == 0) ^ uf.same(j, k)) {
					flag = true;
				}
			}
		}
		if (flag) {
			continue;
		}
		int cnt{};
		for (int j = 1; j <= N; ++j) {
			cnt += (i & (1 << (j - 1)) ? 1 : -1) * A[j];
		}
		ans = min(ans, abs(cnt));
	}
	cout << (ans == INF ? -1 : ans) << "\n";
	return 0;
}
