#include <bits/stdc++.h>

using namespace std;

using cd = complex<double>;

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

deque<bool> sieve() {
	deque<bool> p(1000001, true);
	p[0] = p[1] = false;
	for (int i = 2; i < p.size(); ++i) {
		if (p[i]) {
			for (int j = 2 * i; j < p.size(); j += i) {
				p[j] = false;
			}
		}
	}
	return p;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	deque<bool> p = sieve();
	vector<cd> f(1 << 20);
	vector<cd> g(1 << 20);
	for (int i = 2; i < p.size(); ++i) {
		if (p[i]) {
			f[i / 2] = 1;
			if (2 * i < p.size()) {
				g[i] = 1;
			}
		}
	}
	fft(f), fft(g);
	for (int i = 0; i < f.size(); ++i) {
		f[i] *= g[i];
	}
	fft(f, -1);
	int T{};
	cin >> T;
	while (T--) {
		int x{};
		cin >> x;
		cout << lround(f[x / 2].real()) << "\n";
	}
	return 0;
}
