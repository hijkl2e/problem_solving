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
	int M{};
	cin >> N >> M;
	vector<int> A(6);
	for (int i = 0; i < 6; i += 2) {
		cin >> A[i];
	}
	for (int i = 1; i < 6; i += 2) {
		cin >> A[i];
	}
	mat B(3 * (M + 1), vector<ll>(3 * (M + 1)));
	mat C(3 * (M + 1), vector<ll>(1));
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j <= M; ++j) {
			for (int k = 0; k < 6; ++k) {
				int l = min(j + A[k] / (i == k / 2 ? 2 : 1), M);
				++B[k / 2 * (M + 1) + l][i * (M + 1) + j];
			}
		}
	}
	for (int i = 0; i < 6; ++i) {
		++C[i / 2 * (M + 1) + min(A[i], M)][0];
	}
	--N;
	while (N) {
		if (N % 2) {
			C = mul(B, C);
		}
		B = mul(B, B);
		N /= 2;
	}
	ll ans{};
	for (int i = 0; i < 3; ++i) {
		ans = (ans + C[i * (M + 1) + M][0]) % MOD;
	}
	cout << ans << "\n";
	return 0;
}
