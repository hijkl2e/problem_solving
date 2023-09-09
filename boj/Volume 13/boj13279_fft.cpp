#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using cd = complex<double>;

const ll MOD = 100003;
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
	if (r.size() != n / 2) {
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
	vector<vector<cd>> A(N, vector<cd>(4));
	for (int i = 0; i < N; ++i) {
		A[i][0] = 1;
		cin >> A[i][1];
	}
	while (A.size() > 1) {
		int sz = 2 * A[0].size();
		vector<vector<cd>> B((A.size() + 1) / 2);
		for (int i = 0; i < A.size(); i += 2) {
			if (i + 1 == A.size()) {
				A[i].resize(sz);
				swap(B[i / 2], A[i]);
				break;
			}
			A[i].resize(sz);
			A[i + 1].resize(sz);
			fft(A[i]);
			fft(A[i + 1]);
			for (int j = 0; j < sz; ++j) {
				A[i][j] *= A[i + 1][j];
			}
			fft(A[i], true);
			swap(B[i / 2], A[i]);
		}
		for (int i = 0; i < B.size(); ++i) {
			for (int j = 0; j < B[i].size(); ++j) {
				B[i][j] = llround(B[i][j].real()) % MOD;
			}
		}
		swap(A, B);
	}
	int Q{};
	cin >> Q;
	while (Q--) {
		int x{};
		cin >> x;
		cout << lround(A[0][x].real()) << "\n";
	}
	return 0;
}
