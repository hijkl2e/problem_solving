#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const ll MOD = 998244353;

class UF {
public:
	UF(int N) : par(N), sz(N, 1), f(N) {
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
			return f[x] ? false : (f[x] = true);
		} else if (f[x] && f[y]) {
			return false;
		}
		if (sz[x] < sz[y]) {
			swap(x, y);
		}
		par[y] = x;
		sz[x] += sz[y];
		f[x] |= f[y];
		return true;
	}
	int size(int x) {
		return sz[root(x)];
	}
private:
	vector<int> par, sz;
	deque<bool> f;
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T{};
	cin >> T;
	while (T--) {
		int N{};
		cin >> N;
		vector<int> A(N);
		vector<int> B(N);
		for (int i = 0; i < N; ++i) {
			cin >> A[i];
		}
		for (int i = 0; i < N; ++i) {
			cin >> B[i];
		}
		UF uf(N + 1);
		ll ans = 1;
		for (int i = 0; i < N; ++i) {
			ans &= uf.unite(A[i], B[i]);
		}
		deque<bool> C(N + 1);
		for (int i = 0; i < N; ++i) {
			if (A[i] == B[i]) {
				C[uf.root(A[i])] = true;
			}
		}
		for (int i = 1; i <= N; ++i) {
			if (uf.root(i) == i) {
				ans = (C[i] ? N : 2) * ans % MOD;
			}
		}
		cout << ans << "\n";
	}
	return 0;
}
