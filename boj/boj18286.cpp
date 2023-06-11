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

bool solve(int M, int x, int y) {
	for (int i = 0; i < M - 1; ++i) {
		if (((x >> i) & 1) == ((x >> (i + 1)) & 1) && ((x >> i) & 3) == ((y >> i) & 3)) {
			return false;
		}
	}
	return true;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	ll N{}, M{};
	cin >> N >> M;
	mat A(1 << M, vector<ll>(1 << M));
	for (int i = 0; i < A.size(); ++i) {
		for (int j = 0; j < A.size(); ++j) {
			if (solve(M, i, j)) {
				A[j][i] = 1;
			}
		}
	}
	mat B(1 << M, vector<ll>(1 << M, 1));
	--N;
	while (N) {
		if (N % 2) {
			B = mul(A, B);
		}
		A = mul(A, A);
		N /= 2;
	}
	ll ans{};
	for (int i = 0; i < B.size(); ++i) {
		ans += B[i][0];
	}
	ans %= MOD;
	cout << ans << "\n";
	return 0;
}
