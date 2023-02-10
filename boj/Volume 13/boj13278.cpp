#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using cd = complex<double>;

const ll MOD = 99991;
const double pi = acos(-1);

void fft(vector<cd> &a, bool inv = false) {
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
	static vector<cd> r, ir;
	if (r.size() != n / 2) {
		r.resize(n / 2);
		ir.resize(n / 2);
		for (int i = 0; i < r.size(); ++i) {
			r[i] = cd(cos(2 * pi / n * i), sin(2 * pi / n * i));
			ir[i] = conj(r[i]);
		}
	}
	for (int m = 2; m <= n; m *= 2) {
		for (int k = 0; k < n; k += m) {
			for (int j = 0; j < m / 2; ++j) {
				cd u = a[k + j];
				cd t = a[k + j + m / 2] * (inv ? ir[n / m * j] : r[n / m * j]);
				a[k + j] = u + t;
				a[k + j + m / 2] = u - t;
			}
		}
	}
	if (inv) {
		for (int i = 0; i < n; ++i) {
			a[i] /= n;
		}
	}
}

int N, K;
vector<ll> A(1 << 16);

void solve(vector<vector<cd>> &F, int sz) {
	if (sz == 1) {
		return;
	}
	solve(F, sz / 2);
	for (int i = 0; i < F.size(); i += sz) {
		auto &f = F[i];
		auto &g = F[i + sz / 2];
		f.resize((sz < 8 ? 2 : 1) * sz);
		g.resize((sz < 8 ? 2 : 1) * sz);
		fft(f), fft(g);
		for (int j = 0; j < f.size(); ++j) {
			f[j] *= g[j];
		}
		fft(f, true);
		for (int j = 0; j < f.size(); ++j) {
			f[j] = llround(f[j].real()) % MOD;
		}
	}
}

ll solve(ll x) {
	vector<ll> B(33330);
	B[0] = 1;
	for (int i = 1; i < B.size(); ++i) {
		B[i] = B[i - 1] * x % MOD;
	}
	vector<vector<cd>> F(1 << 16, vector<cd>(4));
	for (int i = 0; i < F.size(); ++i) {
		if (A[i]) {
			F[i][0] = B[A[i] % 33330];
			F[i][1] = 1;
		} else {
			F[i][0] = 1;
		}
	}
	solve(F, 1 << 16);
	return llround(F[0][N - K].real());
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> N >> K;
	for (int i = 0, j = 0; i < N; ++i, ++j) {
		if (j % 8 == 7) {
			++j;
		}
		cin >> A[j];
	}
	ll ans = 22019 * (solve(55048) - solve(44944) + MOD) % MOD;
	cout << ans << "\n";
	return 0;
}
