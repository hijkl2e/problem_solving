#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const ll INF = 0x3f3f3f3f3f3f3f3f;

int N, M;
vector<ll> A, B;
ll dp[1001][1001][2];

ll solve(int x, int y, int z, ll w) {
	if (dp[x][y][z] != INF) {
		return dp[x][y][z];
	}
	ll &ret = dp[x][y][z];
	if (x) {
		ret = min(ret, ((z ? A[y] : A[x]) - A[x - 1]) * w + solve(x - 1, y, 0, w - B[x - 1]));
	}
	if (y + 1 < N) {
		ret = min(ret, (A[y + 1] - (z ? A[y] : A[x])) * w + solve(x, y + 1, 1, w - B[y + 1]));
	}
	return ret;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> N >> M;
	A.resize(N);
	B.resize(N);
	for (int i = 0; i < N; ++i) {
		cin >> A[i] >> B[i];
	}
	memset(dp, 0x3f, sizeof dp);
	dp[0][N - 1][0] = dp[0][N - 1][1] = 0;
	ll sum = accumulate(B.begin(), B.end(), 0LL) - B[M - 1];
	cout << solve(M - 1, M - 1, 0, sum) << "\n";
	return 0;
}
