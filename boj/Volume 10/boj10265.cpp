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
	int N{}, K{};
	cin >> N >> K;
	vector<int> A(N + 1);
	for (int i = 1; i <= N; ++i) {
		cin >> A[i];
	}
	UF uf(N + 1);
	for (int i = 1; i <= N; ++i) {
		uf.unite(i, A[i]);
	}
	vector<int> ind(N + 1);
	for (int i = 1; i <= N; ++i) {
		++ind[A[i]];
	}
	queue<int> q;
	for (int i = 1; i <= N; ++i) {
		if (ind[i] == 0) {
			q.push(i);
		}
	}
	while (q.size()) {
		int x = q.front(); q.pop();
		int y = A[x];
		if (--ind[y] == 0) {
			q.push(y);
		}
	}
	vector<int> B(N + 1);
	vector<int> C(N + 1);
	for (int i = 1; i <= N; ++i) {
		int r = uf.root(i);
		++C[r];
		if (ind[i] == 1) {
			++B[r];
		}
	}
	deque<bool> dp(K + 1);
	dp[0] = true;
	for (int i = 1; i <= N; ++i) {
		if (B[i] == 0) {
			continue;
		}
		for (int j = K - B[i]; j >= 0; --j) {
			if (dp[j]) {
				fill(dp.begin() + j + B[i], dp.begin() + min(j + C[i], K) + 1, true);
			}
		}
	}
	int ans = K;
	while (!dp[ans]) {
		--ans;
	}
	cout << ans << "\n";
	return 0;
}
