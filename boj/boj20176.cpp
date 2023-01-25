#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using cd = complex<double>;

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

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	vector<vector<int>> A(3);
	for (int i = 0; i < 3; ++i) {
		int N{};
		cin >> N;
		A[i].resize(N);
		for (int j = 0; j < N; ++j) {
			cin >> A[i][j];
			A[i][j] += 1 << 15;
		}
	}
	vector<cd> f(1 << 17);
	vector<cd> g(1 << 17);
	for (int i = 0; i < A[0].size(); ++i) {
		f[A[0][i]] += 1;
	}
	for (int i = 0; i < A[2].size(); ++i) {
		g[A[2][i]] += 1;
	}
	fft(f), fft(g);
	for (int i = 0; i < f.size(); ++i) {
		f[i] *= g[i];
	}
	fft(f, true);
	ll ans{};
	for (int i = 0; i < A[1].size(); ++i) {
		ans += lround(f[2 * A[1][i]].real());
	}
	cout << ans << "\n";
	return 0;
}
