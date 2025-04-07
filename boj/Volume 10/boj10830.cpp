#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using mat = vector<vector<int>>;

mat mul(mat &m1, mat &m2) {
	mat ret = mat(m1.size(), vector<int>(m2[0].size()));
	for (int i = 0; i < ret.size(); ++i) {
		for (int j = 0; j < ret[i].size(); ++j) {
			for (int k = 0; k < m2.size(); ++k) {
				ret[i][j] += m1[i][k] * m2[k][j];
			}
			ret[i][j] %= 1000;
		}
	}
	return ret;
}

mat pow(mat &m, ll y) {
	int n = m.size();
	mat ret = mat(n, vector<int>(n));
	for (int i = 0; i < n; ++i) {
		ret[i][i] = 1;
	}
	while (y) {
		if (y % 2) {
			ret = mul(ret, m);
		}
		m = mul(m, m);
		y /= 2;
	}
	return ret;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	ll N{}, B{};
	cin >> N >> B;
	mat A(N, vector<int>(N));
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			cin >> A[i][j];
		}
	}
	mat C = pow(A, B);
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			cout << C[i][j] << (j == N - 1 ? "\n" : " ");
		}
	}
	return 0;
}
