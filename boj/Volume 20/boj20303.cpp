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
	int N{}, M{}, K{};
	cin >> N >> M >> K;
	vector<int> A(N);
	for (int i = 0; i < N; ++i) {
		cin >> A[i];
	}
	UF uf(N);
	while (M--) {
		int u{}, v{};
		cin >> u >> v;
		uf.unite(u - 1, v - 1);
	}
	vector<int> B(N);
	vector<int> C(N);
	for (int i = 0; i < N; ++i) {
		int x = uf.root(i);
		B[x] += A[i];
		++C[x];
	}
	vector<int> dp(K, -INF);
	dp[0] = 0;
	for (int i = 0; i < N; ++i) {
		if (C[i] == 0) {
			continue;
		}
		for (int j = K - 1; j >= C[i]; --j) {
			dp[j] = max(dp[j], dp[j - C[i]] + B[i]);
		}
	}
	int ans = *max_element(dp.begin(), dp.end());
	cout << ans << "\n";
	return 0;
}
