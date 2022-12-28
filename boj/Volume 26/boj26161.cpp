#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using cd = complex<long double>;

const ll MOD = 1e9 + 7;
const double pi = acos(-1);

void fft(vector<cd> &a, int d = 1) {
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
	for (int m = 2; m <= n; m *= 2) {
		cd wm = exp(cd{0, d * 2 * pi / m});
		for (int k = 0; k < n; k += m) {
			cd w = 1;
			for (int j = 0; j < m / 2; ++j) {
				cd u = a[k + j];
				cd t = w * a[k + j + m / 2];
				a[k + j] = u + t;
				a[k + j + m / 2] = u - t;
				w *= wm;
			}
		}
	}
	if (d == -1) {
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
	if (G[x].size() == 1 && d) {
		f[d] += 1;
	}
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
	fft(f, -1);
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
