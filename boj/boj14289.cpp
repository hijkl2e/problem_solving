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
	mat A(N, vector<ll>(N));
	while (M--) {
		int u{}, v{};
		cin >> u >> v;
		--u, --v;
		A[u][v] = A[v][u] = 1;
	}
	mat B(N, vector<ll>(1));
	B[0][0] = 1;
	int D{};
	cin >> D;
	while (D) {
		if (D % 2) {
			B = mul(A, B);
		}
		A = mul(A, A);
		D /= 2;
	}
	cout << B[0][0] << "\n";
	return 0;
}
