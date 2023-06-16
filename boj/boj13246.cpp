#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using mat = vector<vector<ll>>;

const ll MOD = 1e3;

mat add(const mat &m1, const mat &m2) {
	mat ret = m1;
	for (int i = 0; i < m1.size(); ++i) {
		for (int j = 0; j < m1[i].size(); ++j) {
			ret[i][j] = (ret[i][j] + m2[i][j]) % MOD;
		}
	}
	return ret;
}

mat mul(const mat &m1, const mat &m2) {
	mat ret = mat(m1.size(), vector<ll>(m2[0].size()));
	for (int i = 0; i < ret.size(); ++i) {
		for (int j = 0; j < ret[i].size(); ++j) {
			for (int k = 0; k < m2.size(); ++k) {
				ret[i][j] = (ret[i][j] + m1[i][k] * m2[k][j]) % MOD;
			}
		}
	}
	return ret;
}

mat pow(mat A, ll x) {
	mat B(A.size(), vector<ll>(A.size()));
	for (int i = 0; i < B.size(); ++i) {
		B[i][i] = 1;
	}
	while (x) {
		if (x % 2) {
			B = mul(A, B);
		}
		A = mul(A, A);
		x /= 2;
	}
	return B;
}

mat solve(mat A, ll x) {
	if (x == 1) {
		return A;
	}
	mat B = solve(A, x / 2);
	B = add(B, mul(B, pow(A, x / 2)));
	if (x % 2) {
		B = add(B, pow(A, x));
	}
	return B;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	ll N{}, M{};
	cin >> N >> M;
	mat A(N, vector<ll>(N));
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			cin >> A[i][j];
			A[i][j] %= MOD;
		}
	}
	mat B = solve(A, M);
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			cout << B[i][j] << (j == N - 1 ? "\n" : " ");
		}
	}
	return 0;
}
