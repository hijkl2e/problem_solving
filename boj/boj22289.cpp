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
	vector<string> s(2);
	cin >> s[0] >> s[1];
	vector<vector<cd>> f(2, vector<cd>(1 << 19));
	for (int i = 0; i < 2; ++i) {
		for (int j = s[i].size() - 1, k = 0; j >= 0; --j) {
			k = 10 * k + s[i][s[i].size() - j - 1] - '0';
			if (j % 4 == 0) {
				f[i][j / 4] = k;
				k = 0;
			}
		}
	}
	fft(f[0]);
	fft(f[1]);
	for (int i = 0; i < f[0].size(); ++i) {
		f[0][i] *= f[1][i];
	}
	fft(f[0], true);
	vector<ll> A(f[0].size());
	for (int i = 0; i < A.size() - 1; ++i) {
		A[i] += lround(f[0][i].real());
		A[i + 1] += A[i] / 10000;
		A[i] %= 10000;
	}
	bool flag{};
	for (int i = A.size() - 1; i >= 0; --i) {
		if (flag) {
			cout << setw(4) << setfill('0') << A[i];
		} else if (A[i] > 0 || i == 0) {
			cout << A[i];
			flag = true;
		}
	}
	cout << "\n";
	return 0;
}
