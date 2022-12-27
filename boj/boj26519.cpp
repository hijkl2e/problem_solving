#include <bits/stdc++.h>

using namespace std;

using ll = long long;

struct frac {
	frac() { }
	frac(ll _d, ll _n) : d(_d), n(_n) {
		if (d < 0) {
			d = -d, n = -n;
		}
	}
	bool operator<(const frac &f) const {
		return n * f.d < d * f.n;
	}
	frac operator+(const frac &f) const {
		return frac(d * f.d, n * f.d + d * f.n);
	}
	ll d{}, n{};
};

struct edge {
	edge() { }
	edge(int _u, int _v, int _b, int _c) : u(_u), v(_v), b(_b), c(_c) { }
	int u{}, v{}, b{}, c{};
};

const ll MOD = 1e9 + 7;

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

ll pow(ll x, ll y) {
	ll ret = 1;
	while (y) {
		if (y % 2) {
			ret = ret * x % MOD;
		}
		x = x * x % MOD;
		y /= 2;
	}
	return ret;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, M{}, a{};
	cin >> N >> M >> a;
	vector<edge> E(M);
	for (int i = 0; i < M; ++i) {
		cin >> E[i].u >> E[i].v >> E[i].b >> E[i].c;
	}
	ll t1{}, t2{};
	cin >> t1 >> t2;
	frac T1(1, t1);
	frac T2(1, t2);
	set<frac> F{T1, T2};
	for (int i = 0; i < M; ++i) {
		for (int j = i + 1; j < M; ++j) {
			if (E[i].b == E[j].b) {
				continue;
			}
			frac f(E[i].b - E[j].b, E[j].c - E[i].c);
			if (T1 < f && f < T2) {
				F.insert(f);
			}
		}
	}
	ll ans{};
	auto it = F.begin();
	while (true) {
		const frac &f1 = *it++;
		if (it == F.end()) {
			break;
		}
		const frac &f2 = *it;
		frac f = f1 + f2;
		f.d *= 2;
		sort(E.begin(), E.end(), [&](edge &e1, edge &e2) {
			return e1.b * f.n + e1.c * f.d < e2.b * f.n + e2.c * f.d;
		});
		int B{}, C{};
		UF uf(N + 1);
		for (auto e : E) {
			if (uf.unite(e.u, e.v)) {
				B += e.b;
				C += e.c;
			}
		}
		ll d = pow(f1.d * f2.d, MOD - 2);
		ll t1 = f1.n * f2.d * d % MOD;
		ll t2 = f2.n * f1.d * d % MOD;
		ans = (ans + (t2 - t1) * (B * (t1 + t2) % MOD + 2 * C)) % MOD;
	}
	ans = 500000004LL * ans + 333333336LL * (N - 1) * a % MOD * (t2 * t2 * t2 - t1 * t1 * t1);
	ans = (ans % MOD + MOD) % MOD;
	cout << ans << "\n";
	return 0;
}
