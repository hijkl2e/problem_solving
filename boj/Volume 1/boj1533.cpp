#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using mat = vector<vector<ll>>;

const ll MOD = 1e6 + 3;

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
	int N{}, S{}, E{}, T{};
	cin >> N >> S >> E >> T;
	cin.ignore();
	vector<string> G(N);
	for (int i = 0; i < N; ++i) {
		getline(cin, G[i]);
	}
	mat A(5 * N, vector<ll>(5 * N));
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			int x = G[i][j] - '0';
			if (x == 0) {
				continue;
			}
			A[j][(x - 1) * N + i] = 1;
		}
	}
	for (int i = N; i < A.size(); ++i) {
		A[i][i - N] = 1;
	}
	mat B(5 * N, vector<ll>(1));
	B[S - 1][0] = 1;
	while (T) {
		if (T % 2) {
			B = mul(A, B);
		}
		A = mul(A, A);
		T /= 2;
	}
	cout << B[E - 1][0] << "\n";
	return 0;
}
