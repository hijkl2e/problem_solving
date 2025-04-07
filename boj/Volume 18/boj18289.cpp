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
	ll N{};
	int K{};
	cin >> N >> K;
	mat A(4 * max(K, 1), vector<ll>(4 * max(K, 1)));
	for (int i = 0; i == 0 || i < K; ++i) {
		for (int j = 0; j < 2; ++j) {
			for (int k = 0; k < 2; ++k) {
				if (K) {
					++A[(i + 1) % K * 4 + k][4 * i + 2 * j + k];
				}
				if (j == 0) {
					++A[4 * i + k + 2][4 * i + k];
				}
				++A[4 * i + 1][4 * i + 2 * j + k];
			}
		}
	}
	mat B(4 * max(K, 1), vector<ll>(1));
	B[0][0] = 1;
	while (N) {
		if (N % 2) {
			B = mul(A, B);
		}
		A = mul(A, A);
		N /= 2;
	}
	ll ans = (B[1][0] + B[3][0]) % MOD;
	cout << ans << "\n";
	return 0;
}
