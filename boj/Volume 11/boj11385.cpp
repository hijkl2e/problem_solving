#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using cd = complex<long double>;

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
		fft(tp, -1);
		for (int j = 0; j < tp.size(); ++j) {
			B[j] += llround(tp[j].real()) << (i == 3 ? 20 : i == 0 ? 0 : 10);
		}
	}
	ll ans{};
	for (int i = 0; i < B.size(); ++i) {
		ans ^= B[i];
	}
	cout << ans << "\n";
	return 0;
}
