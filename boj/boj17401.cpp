#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using mat = vector<vector<ll>>;

const ll MOD = 1e9 + 7;

mat mul(mat &m1, mat &m2) {
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

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T{}, N{}, D{};
	cin >> T >> N >> D;
	vector<mat> A(T + 1, mat(N + 1, vector<ll>(N + 1)));
	for (int i = 1; i <= N; ++i) {
		A[0][i][i] = 1;
	}
	for (int i = 1; i <= T; ++i) {
		int M{};
		cin >> M;
		while (M--) {
			int a{}, b{}, c{};
			cin >> a >> b >> c;
			A[i][a][b] = c;
		}
		A[i] = mul(A[i - 1], A[i]);
	}
	mat B(N + 1, vector<ll>(N + 1));
	for (int i = 1; i <= N; ++i) {
		B[i][i] = 1;
	}
	int d = D / T;
	while (d) {
		if (d % 2) {
			B = mul(B, A[T]);
		}
		A[T] = mul(A[T], A[T]);
		d /= 2;
	}
	B = mul(B, A[D % T]);
	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= N; ++j) {
			cout << B[i][j] << (j == N ? "\n" : " ");
		}
	}
	return 0;
}
