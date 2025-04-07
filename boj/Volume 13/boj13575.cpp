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
	int N{}, K{};
	cin >> N >> K;
	vector<cd> A(1024);
	for (int i = 0; i < N; ++i) {
		int x{};
		cin >> x;
		A[x] = 1;
	}
	vector<cd> B(1024);
	B[0] = 1;
	while (K) {
		A.resize(2 * A.size());
		B.resize(2 * B.size());
		fft(A);
		if (K % 2) {
			fft(B);
			for (int i = 0; i < B.size(); ++i) {
				B[i] *= A[i];
			}
			fft(B, true);
			for (int i = 0; i < B.size(); ++i) {
				B[i] = lround(B[i].real()) ? 1 : 0;
			}
		}
		for (int i = 0; i < A.size(); ++i) {
			A[i] *= A[i];
		}
		fft(A, true);
		for (int i = 0; i < A.size(); ++i) {
			A[i] = lround(A[i].real()) ? 1 : 0;
		}
		K /= 2;
	}
	vector<int> C;
	for (int i = 1; i < B.size(); ++i) {
		if (lround(B[i].real())) {
			C.push_back(i);
		}
	}
	for (int i = 0; i < C.size(); ++i) {
		cout << C[i] << (i == C.size() - 1 ? "\n" : " ");
	}
	return 0;
}
