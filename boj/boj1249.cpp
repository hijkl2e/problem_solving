#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using mat = vector<vector<ll>>;

const ll MOD = 1234567891;

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
	int N{}, K{};
	cin >> N >> K;
	mat A(K + 2, vector<ll>(K + 2));
	for (int i = 0; i < K; ++i) {
		A[i + 1][i] = 26 - i;
		A[i][i] = i;
	}
	A[K][K] = K;
	fill(A[K + 1].begin() + 1, A[K + 1].end(), 1);
	mat B(K + 2, vector<ll>(1));
	B[0][0] = 1;
	int M = (N + 1) / 2;
	while (M) {
		if (M % 2) {
			B = mul(A, B);
		}
		A = mul(A, A);
		M /= 2;
	}
	ll ans{};
	for (int i = 0; i < K + 2; ++i) {
		ans += (i < K + 1 && N % 2 ? 1 : 2) * B[i][0];
	}
	ans %= MOD;
	cout << ans << "\n";
	return 0;
}
