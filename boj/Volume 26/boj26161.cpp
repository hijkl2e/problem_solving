#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using cd = complex<double>;

const ll MOD = 1e9 + 7;
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
	if (r.empty()) {
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

vector<vector<int>> G;
vector<cd> f(1 << 20);

void dfs(int x, int p, int d) {
	for (int y : G[x]) {
		if (y == p) {
			continue;
		}
		dfs(y, x, d + 1);
	}
	f[d] += (G[x].size() == 1 && d);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, R{};
	cin >> N >> R;
	G.resize(N + 1);
	for (int i = 0; i < N - 1; ++i) {
		int u{}, v{};
		cin >> u >> v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	dfs(R, -1, 0);
	fft(f);
	for (int i = 0; i < f.size(); ++i) {
		f[i] *= f[i];
	}
	fft(f, true);
	vector<ll> psum(N + 1);
	for (int i = 2; i <= N; ++i) {
		psum[i] = psum[i - 1] + llround(f[i].real());
	}
	int Q{};
	cin >> Q;
	while (Q--) {
		int a{}, b{};
		cin >> a >> b;
		cout << (psum[b] - psum[a - 1]) % MOD << "\n";
	}
	return 0;
}
