#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const ll MOD = 1e9 + 7;

vector<ll> mul(vector<ll> &A, vector<ll> &B) {
	int n = A.size();
	vector<ll> C(n);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			int k = (i + j) % n;
			C[k] = (C[k] + A[i] * B[j]) % MOD;
		}
	}
	return C;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	ll N{}, K{};
	cin >> N >> K;
	vector<ll> x(N);
	vector<ll> y(N);
	for (int i = 0; i < N; ++i) {
		cin >> x[i] >> y[i];
	}
	vector<ll> A(N);
	vector<ll> B(N);
	A[0] = A[1] = 500000004;
	B[0] = 1;
	while (K) {
		if (K % 2) {
			B = mul(A, B);
		}
		A = mul(A, A);
		K /= 2;
	}
	fill(A.begin(), A.end(), 0);
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			A[i] = (A[i] + B[j] * x[(i + j) % N]) % MOD;
		}
	}
	swap(x, A);
	fill(A.begin(), A.end(), 0);
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			A[i] = (A[i] + B[j] * y[(i + j) % N]) % MOD;
		}
	}
	swap(y, A);
	ll ans{};
	for (int i = 0; i < N; ++i) {
		int j = (i + 1) % N;
		ans += (x[j] * y[i] - x[i] * y[j]) % MOD;
	}
	ans = (ans % MOD + MOD) * 500000004 % MOD;
	cout << ans << "\n";
	return 0;
}
