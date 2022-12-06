#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using cd = complex<long double>;

const ll MOD = 1e9 + 7;
const double pi = acos(-1);

vector<cd> fft(vector<cd> &a, int d = 1) {
	int n = a.size();
	vector<cd> r(n);
	for (int k = 0; k < n; ++k) {
		int b{};
		for (int z = 1; z < n; z *= 2) {
			b *= 2;
			if (k & z) {
				++b;
			}
		}
		r[b] = a[k];
	}
	for (int m = 2; m <= n; m *= 2) {
		cd wm = exp(cd{0, d * 2 * pi / m});
		for (int k = 0; k < n; k += m) {
			cd w = 1;
			for (int j = 0; j < m / 2; ++j) {
				cd u = r[k + j];
				cd t = w * r[k + j + m / 2];
				r[k + j] = u + t;
				r[k + j + m / 2] = u - t;
				w *= wm;
			}
		}
	}
	if (d == -1) {
		for (int i = 0; i < n; ++i) {
			r[i] /= n;
		}
	}
	return r;
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
		f[d] += cd{1};
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
	auto tf = fft(f);
	for (int i = 0; i < tf.size(); ++i) {
		tf[i] *= tf[i];
	}
	auto res = fft(tf, -1);
	vector<ll> psum(N + 1);
	for (int i = 2; i <= N; ++i) {
		psum[i] = psum[i - 1] + llround(res[i].real());
	}
	int Q{};
	cin >> Q;
	while (Q--) {
		int W{}, V{};
		cin >> W >> V;
		cout << (psum[V] - psum[W - 1]) % MOD << "\n";
	}
	return 0;
}
