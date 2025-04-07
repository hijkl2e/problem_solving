#include <bits/stdc++.h>

using namespace std;

int N, K;
vector<vector<int>> dp;
deque<bool> A;

bool solve(int t, int x) {
	if (dp[t][x] != -1) {
		return dp[t][x];
	}
	for (int i = 1; i <= K && x + i <= N; ++i) {
		if (A[x + i]) {
			continue;
		}
		if (solve(t ^ 1, x + i) == t) {
			return dp[t][x] = t;
		}
	}
	return dp[t][x] = (t ^ 1);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> N >> K;
	A.resize(N + 1);
	int x{};
	while (cin >> x) {
		A[x] = true;
	}
	dp.assign(2, vector<int>(N + 1, -1));
	cout << solve(1, 0) << "\n";
	return 0;
}
