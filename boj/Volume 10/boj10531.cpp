#include <bits/stdc++.h>

using namespace std;

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
	int N{};
	cin >> N;
	vector<cd> f(1 << 19);
	f[0] = 1;
	while (N--) {
		int x{};
		cin >> x;
		f[x] = 1;
	}
	fft(f);
	for (int i = 0; i < f.size(); ++i) {
		f[i] *= f[i];
	}
	fft(f, true);
	int M{};
	cin >> M;
	int ans{};
	while (M--) {
		int x{};
		cin >> x;
		if (lround(f[x].real())) {
			++ans;
		}
	}
	cout << ans << "\n";
	return 0;
}
