#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using mat = vector<vector<ll>>;

const ll MOD = 1e9 + 9;

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
	int x1 = x >> M;
	int x2 = x & ((1 << M) - 1);
	for (int i = 0; i < M; ++i) {
		if ((y & (1 << i)) == 0) {
			continue;
		}
		if ((x1 & (1 << (i + 1))) || (i && (x1 & (1 << (i - 1))))
				|| (x2 & (1 << (i + 2))) || (i > 1 && (x2 & (1 << (i - 2))))) {
			return false;
		}
	}
	return true;
}

bool solve(int M, int x) {
	int x1 = x >> M;
	int x2 = x & ((1 << M) - 1);
	for (int i = 0; i < M; ++i) {
		if ((x2 & (1 << i)) == 0) {
			continue;
		}
		if ((x1 & (1 << (i + 2))) || (i > 1 && (x1 & (1 << (i - 2))))) {
			return false;
		}
	}
	return true;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T{};
	cin >> T;
	while (T--) {
		int M{}, N{};
		cin >> M >> N;
		mat A(1 << (2 * M), vector<ll>(1 << (2 * M)));
		for (int i = 0; i < A.size(); ++i) {
			for (int j = 0; j < (1 << M); ++j) {
				if (solve(M, i, j)) {
					A[((i << M) | j) % A.size()][i] = 1;
				}
			}
		}
		for (int i = A.size() - 1; i >= 0; --i) {
			if (solve(M, i)) {
				continue;
			}
			A.erase(A.begin() + i);
			for (int j = 0; j < A.size(); ++j) {
				A[j].erase(A[j].begin() + i);
			}
		}
		mat B(A.size(), vector<ll>(1));
		B[0][0] = 1;
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
	}
	return 0;
}
