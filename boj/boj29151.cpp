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

int A[6];
vector<int> B[7];
vector<int> C[7];
mat D[7][60];

void solve1(int n, int x, int y, int z) {
	B[n].push_back(y);
	C[n].push_back(z);
	if (n == 6) {
		return;
	}
	for (int i = 0; i <= x; ++i) {
		if (n && A[n - 1] == i) {
			continue;
		}
		A[n] = i;
		solve1(n + 1, x + (i == x), y | (i << (3 * n)), z * (i == x ? 16 - x : 1));
	}
}

int solve2(int n, int x, int y, int z, int k, int l) {
	int ret{};
	if (k == n) {
		ret = 1;
		while (l--) {
			ret *= 10 - l;
		}
		return ret;
	}
	int u = (B[n][x] >> (3 * k)) & 7;
	int v = (B[n][y] >> (3 * k)) & 7;
	if (A[u] != -1) {
		return A[u] == v ? 0 : solve2(n, x, y, z, k + 1, l);
	}
	for (int i = 0; i < 7; ++i) {
		if (i < 6 && ((z & (1 << i)) || i == v)) {
			continue;
		}
		A[u] = i;
		ret += solve2(n, x, y, z | (1 << i), k + 1, l + (i == 6));
		A[u] = -1;
	}
	return ret;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	solve1(0, 0, 0, 1);
	memset(A, -1, sizeof A);
	for (int i = 1; i < 7; ++i) {
		int sz = B[i].size();
		D[i][0].assign(sz, vector<ll>(sz));
		for (int j = 0; j < sz; ++j) {
			for (int k = 0; k < sz; ++k) {
				D[i][0][j][k] = solve2(i, j, k, 0, 0, 0);
			}
		}
	}
	for (int i = 1; i < 7; ++i) {
		for (int j = 1; j < 60; ++j) {
			D[i][j] = mul(D[i][j - 1], D[i][j - 1]);
		}
	}
	int Q{};
	cin >> Q;
	while (Q--) {
		ll h{}, w{};
		cin >> h >> w;
		--w;
		mat E(B[h].size(), vector<ll>(1));
		for (int i = 0; i < E.size(); ++i) {
			E[i][0] = C[h][i];
		}
		for (int i = 0; w; ++i) {
			if (w % 2) {
				E = mul(D[h][i], E);
			}
			w /= 2;
		}
		ll ans{};
		for (int i = 0; i < E.size(); ++i) {
			ans += E[i][0];
		}
		ans %= MOD;
		cout << ans << "\n";
	}
	return 0;
}
