#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const ll P1 = 998244353LL;
const ll P2 = 2281701377LL;

ll pow(ll x, ll y, ll mod) {
	ll ret = 1;
	while (y) {
		if (y % 2) {
			ret = ret * x % mod;
		}
		x = x * x % mod;
		y /= 2;
	}
	return ret;
}

void ntt(vector<ll> &a, ll p, bool inv = false) {
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
	if (r.empty() || ir[1] != pow(r[1], p - 2, p)) {
		r.resize(n / 2);
		ir.resize(n / 2);
		for (int i = 0; i < r.size(); ++i) {
			r[i] = pow(3LL, (p - 1) / n * i, p);
			ir[i] = pow(r[i], p - 2, p);
		}
	}
	for (int m = 2; m <= n; m *= 2) {
		for (int k = 0; k < n; k += m) {
			for (int j = 0; j < m / 2; ++j) {
				ll u = a[k + j];
				ll t = a[k + j + m / 2] * (inv ? ir[n / m * j] : r[n / m * j]) % p;
				a[k + j] = (u + t) % p;
				a[k + j + m / 2] = (u - t) % p;
			}
		}
	}
	if (inv) {
		ll m = pow(1LL * n, p - 2, p);
		for (int i = 0; i < n; ++i) {
			a[i] = a[i] * m % p;
		}
	}
}

vector<ll> solve(vector<ll> f, vector<ll> g, ll p) {
	ntt(f, p), ntt(g, p);
	for (int i = 0; i < f.size(); ++i) {
		f[i] = f[i] * g[i] % p;
	}
	ntt(f, p, true);
	for (int i = 0; i < f.size(); ++i) {
		f[i] = (f[i] + p) % p;
	}
	return f;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, M{};
	cin >> N >> M;
	vector<ll> A(1 << 21);
	vector<ll> B(1 << 21);
	for (int i = 0; i <= N; ++i) {
		cin >> A[i];
	}
	for (int i = 0; i <= M; ++i) {
		cin >> B[i];
	}
	vector<ll> C = solve(A, B, P1);
	vector<ll> D = solve(A, B, P2);
	ll ans{};
	for (int i = 0; i < C.size(); ++i) {
		__int128 x = C[i], y = D[i];
		ans ^= (2024618233623187001LL * x + 253077281199387081LL * y) % (P1 * P2);
	}
	cout << ans << "\n";
	return 0;
}
