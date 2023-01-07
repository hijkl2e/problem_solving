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
	int N{}, M{};
	cin >> N >> M;
	vector<vector<int>> A(2);
	A[0].resize(N + 1);
	A[1].resize(M + 1);
	for (int i = 0; i <= N; ++i) {
		cin >> A[0][i];
	}
	for (int i = 0; i <= M; ++i) {
		cin >> A[1][i];
	}
	vector<vector<cd>> tf(4, vector<cd>(1 << 21));
	for (int i = 0; i < 4; ++i) {
		for (int j = 0; j < A[i / 2].size(); ++j) {
			tf[i][j] = (A[i / 2][j] >> (10 * (i & 1))) & 1023;
		}
		fft(tf[i]);
	}
	vector<ll> B(1 << 21);
	vector<cd> tp(1 << 21);
	for (int i = 0; i < 4; ++i) {
		for (int j = 0; j < tp.size(); ++j) {
			tp[j] = tf[i & 1][j] * tf[(i / 2) | 2][j];
		}
		fft(tp, true);
		for (int j = 0; j < tp.size(); ++j) {
			B[j] += llround(tp[j].real()) << (i == 3 ? 20 : i ? 10 : 0);
		}
	}
	ll ans{};
	for (int i = 0; i < B.size(); ++i) {
		ans ^= B[i];
	}
	cout << ans << "\n";
	return 0;
}
