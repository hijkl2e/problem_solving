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
	int N{}, M{};
	cin >> N >> M;
	if (M == 1) {
		cout << (N == 1 ? 1 : 0) << "\n";
		return 0;
	}
	mat A(M, vector<ll>(M));
	mat B(M, vector<ll>(1, 1));
	for (int i = 0; i < M; ++i) {
		fill(A[i].begin() + max(i - 2, 0), A[i].begin() + min(i + 3, M), 1);
	}
	for (int i = 1; i < M - 1; ++i) {
		++A[i][i];
	}
	int K = (N - 1) / 2;
	while (K) {
		if (K % 2) {
			B = mul(A, B);
		}
		A = mul(A, A);
		K /= 2;
	}
	ll ans{};
	for (int i = 0; i < M; ++i) {
		ans += B[i][0];
	}
	if (N % 2 == 0) {
		ans = 2 * ans - B[0][0] - B[M - 1][0];
	}
	ans %= MOD;
	cout << ans << "\n";
	return 0;
}
