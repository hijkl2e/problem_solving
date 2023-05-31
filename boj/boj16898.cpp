#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const ll INF = 1e9 + 7;

int N;
int dp[31625][31];

ll pow(int x, int y) {
	ll ret = 1;
	while (y-- && ret < INF) {
		ret *= x;
	}
	ret = min(ret, INF);
	return ret;
}

int solve(int x, int y) {
	if (dp[x][y] != -1) {
		return dp[x][y];
	} else if (x == 31624) {
		return (N - x + 1) % 2 * 2;
	}
	int &ret = dp[x][y];
	ret = 2 - (pow(x, y) < N ? min(solve(x + 1, y), solve(x, y + 1)) : 0);
	return ret;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int a{}, b{};
	cin >> a >> b >> N;
	memset(dp, -1, sizeof dp);
	dp[1][30] = 1;
	int res = solve(a, b);
	cout << (res == 0 ? "koosaga" : res == 2 ? "cubelover" : "jh05013") << "\n";
	return 0;
}
