#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ii = pair<int, int>;

const ll MOD = 1e9 + 7;

class UF {
public:
	UF(int N) : par(N), sz(N, 1), nxt(N) {
		for (int i = 0; i < N; ++i) {
			par[i] = nxt[i] = i;
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
		nxt[x] = max(nxt[x], nxt[y]);
		return true;
	}
	int size(int x) {
		return sz[root(x)];
	}
	int next(int x) {
		return nxt[root(x)];
	}
private:
	vector<int> par, sz, nxt;
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, Q{};
	cin >> N >> Q;
	vector<ll> F(N + 1);
	F[0] = F[1] = 1;
	for (int i = 2; i <= N; ++i) {
		F[i] = (F[i - 1] + F[i - 2]) % MOD;
	}
	F[0] = 0;
	vector<ii> A(Q);
	for (int i = Q - 1; i >= 0; --i) {
		cin >> A[i].first >> A[i].second;
	}
	vector<int> B(N + 1);
	UF uf(N + 2);
	for (auto &[u, v] : A) {
		for (int i = uf.next(u); i <= v; i = uf.next(i)) {
			B[i] = i - u + 1;
			uf.unite(i, i + 1);
		}
	}
	for (int i = 1; i <= N; ++i) {
		cout << F[B[i]] << (i == N ? "\n" : " ");
	}
	return 0;
}
