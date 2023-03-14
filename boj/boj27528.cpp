#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const ll INF = 4e18;

vector<ll> A;
vector<vector<ll>> dp;

ll solve(int x, int y) {
	if (dp[x][y] != INF) {
		return dp[x][y];
	} else if (x == 1) {
		return A[x];
	}
	if (y < 3) {
		dp[x][y] = min(solve(x / 2, 3), 0LL);
	} else {
		dp[x][y] = max(solve(x / 2, 0), 0LL);
	}
	if ((x & -x) != x && y % 3 != 2) {
		if (y < 3) {
			dp[x][y] = min(dp[x][y], solve(x - 1, 4));
		} else {
			dp[x][y] = max(dp[x][y], solve(x - 1, 1));
		}
	}
	if (((x + 1) & -(x + 1)) != x + 1 && y % 3 != 1) {
		if (y < 3) {
			dp[x][y] = min(dp[x][y], solve(x + 1, 5));
		} else {
			dp[x][y] = max(dp[x][y], solve(x + 1, 2));
		}
	}
	dp[x][y] += A[x];
	return dp[x][y];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	A.resize(1 << N);
	for (int i = 1; i < A.size(); ++i) {
		cin >> A[i];
	}
	dp.assign(1 << N, vector<ll>(6, INF));
	for (int i = 1; i < dp.size(); ++i) {
		cout << solve(i, 0) << (i == dp.size() - 1 ? "\n" : " ");
	}
	return 0;
}
