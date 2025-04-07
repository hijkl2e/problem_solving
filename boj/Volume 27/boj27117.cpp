#include <bits/stdc++.h>

using namespace std;

using ll = long long;

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
	ll N{};
	cin >> N;
	vector<int> A(N + 1);
	for (int i = 1; i <= N; ++i) {
		cin >> A[i];
	}
	UF uf(N + 1);
	for (int i = 1; i <= N; ++i) {
		uf.unite(i, A[i]);
	}
	ll ans = 3 * N + 2;
	ll cnt{};
	for (int i = 1; i <= N; ++i) {
		if (uf.root(i) == i) {
			ll sz = uf.size(i);
			cnt += sz * (sz - 1) / 2;
			ans -= 2;
		}
	}
	ans *= N * (N - 1) / 2;
	ans -= 4 * cnt;
	cout << ans << "\n";
	return 0;
}
