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
	ll N{}, M{};
	cin >> N >> M;
	mat A(5, vector<ll>(5));
	while (M--) {
		int x{};
		cin >> x;
		++A[0][x - 1];
	}
	for (int i = 0; i < 4; ++i) {
		A[i + 1][i] = 1;
	}
	mat B(5, vector<ll>(1));
	B[0][0] = 1;
	while (N) {
		if (N % 2) {
			B = mul(A, B);
		}
		A = mul(A, A);
		N /= 2;
	}
	cout << B[0][0] << "\n";
	return 0;
}
