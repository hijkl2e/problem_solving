#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const ll MOD = 998244353;

vector<ll> M(6);
vector<ll> A(6);
ll dp[11][11][11][11][11][11];

ll pow(ll x, ll y) {
	ll ret = 1;
	while (y) {
		if (y % 2) {
			ret = ret * x % MOD;
		}
		x = x * x % MOD;
		y /= 2;
	}
	return ret;
}

ll solve(int m1, int m2, int m3, int m4, int m5, int m6) {
	ll &ret = dp[m1][m2][m3][m4][m5][m6];
	if (ret != -1) {
		return ret;
	}
	ret = accumulate(A.begin(), A.end(), 0);
	vector<int> B{m1, m2, m3, m4, m5, m6};
	for (int i = 0; i < 6; ++i) {
		if (B[i]) {
			--B[i];
			ret += solve(B[0], B[1], B[2], B[3], B[4], B[5]) * A[i] % MOD;
			++B[i];
		}
	}
	ll sum{};
	for (int i = 0; i < 6; ++i) {
		sum += B[i] ? A[i] : 0;
	}
	ret = ret * pow(sum, MOD - 2) % MOD;
	return ret;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	for (int i = 0; i < N; ++i) {
		cin >> M[i] >> A[i];
	}
	memset(dp, -1, sizeof dp);
	cout << solve(M[0], M[1], M[2], M[3], M[4], M[5]) << "\n";
	return 0;
}
