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
	fft(f, -1);
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