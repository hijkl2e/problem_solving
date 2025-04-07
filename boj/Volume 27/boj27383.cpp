#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const ll MOD = 998244353;

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

void ntt(vector<ll> &a, bool inv = false) {
	int n = a.size();
	for (int k = 0; k < n; ++k) {
		int b{};
		for (int z = 1; z < n; z *= 2) {
			b *= 2;
			if (k & z) {
				++b;
			}
		}
		if (k < b) {
			swap(a[k], a[b]);
		}
	}
	static vector<ll> r, ir;
	if (r.size() != n / 2) {
		r.resize(n / 2);
		ir.resize(n / 2);
		for (int i = 0; i < r.size(); ++i) {
			r[i] = pow(3LL, (MOD - 1) / n * i);
			ir[i] = pow(r[i], MOD - 2);
		}
	}
	for (int m = 2; m <= n; m *= 2) {
		for (int k = 0; k < n; k += m) {
			for (int j = 0; j < m / 2; ++j) {
				ll u = a[k + j];
				ll t = a[k + j + m / 2] * (inv ? ir[n / m * j] : r[n / m * j]) % MOD;
				a[k + j] = (u + t) % MOD;
				a[k + j + m / 2] = (u - t) % MOD;
			}
		}
	}
	if (inv) {
		ll m = pow(1LL * n, MOD - 2);
		for (int i = 0; i < n; ++i) {
			a[i] = a[i] * m % MOD;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, K{};
	cin >> N >> K;
	vector<ll> A(N + 1, -1);
	A[1] = 0;
	for (int i = 0; i < N - 1; ++i) {
		int u{}, v{};
		cin >> u >> v;
		++A[u], ++A[v];
	}
	vector<int> L(N + 1);
	vector<int> R(N + 1);
	for (int i = 1; i <= N; ++i) {
		cin >> L[i] >> R[i];
	}
	vector<ll> fact(K + 1);
	fact[0] = 1;
	for (int i = 1; i <= K; ++i) {
		fact[i] = i * fact[i - 1] % MOD;
	}
	vector<ll> ifact(K + 1);
	ifact[K] = pow(fact[K], MOD - 2);
	for (int i = K - 1; i >= 0; --i) {
		ifact[i] = (i + 1) * ifact[i + 1] % MOD;
	}
	ll ans = 1;
	for (int i = 1; i <= N; ++i) {
		if (A[i] == 0) {
			continue;
		}
		int sz = 1;
		while (sz < 2 * R[i] + 1) {
			sz *= 2;
		}
		vector<ll> f(sz);
		vector<ll> g(sz);
		for (int j = 0; j <= R[i]; ++j) {
			f[j] = ifact[j] * pow(1LL * j, A[i]) % MOD;
			g[j] = ifact[j] * (j % 2 ? -1 : 1);
		}
		ntt(f), ntt(g);
		for (int j = 0; j < f.size(); ++j) {
			f[j] = f[j] * g[j] % MOD;
		}
		ntt(f, true);
		ll x{};
		for (int j = L[i]; j <= R[i]; ++j) {
			x += j * fact[K - 1] % MOD * ifact[K - j] % MOD * f[j] % MOD;
		}
		x %= MOD;
		ans = ans * x % MOD;
	}
	ans = (K * ans % MOD + MOD) % MOD;
	cout << ans << "\n";
	return 0;
}
