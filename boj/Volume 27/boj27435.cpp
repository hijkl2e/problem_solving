#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using mat = vector<vector<ll>>;

const ll MOD = 998244353;

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
	int T{};
	cin >> T;
	while (T--) {
		ll N{};
		cin >> N;
		if (N < 5) {
			cout << (N == 4 ? 2 : 1) << "\n";
			continue;
		}
		N -= 4;
		mat A(5, vector<ll>(5));
		A[0][0] = A[0][4] = 1;
		for (int i = 0; i < 4; ++i) {
			A[i + 1][i] = 1;
		}
		mat B(5, vector<ll>(1));
		B[0][0] = 2;
		B[1][0] = B[2][0] = B[3][0] = 1;
		while (N) {
			if (N % 2) {
				B = mul(A, B);
			}
			A = mul(A, A);
			N /= 2;
		}
		cout << B[0][0] << "\n";
	}
	return 0;
}
