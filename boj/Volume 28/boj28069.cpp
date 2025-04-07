#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9 + 7;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, K{};
	cin >> N >> K;
	vector<int> dp(N + 1, INF);
	dp[0] = 0;
	for (int i = 1; i <= N; ++i) {
		dp[i] = min(dp[i], dp[i - 1] + 1);
		int x = i + i / 2;
		if (x <= N) {
			dp[x] = min(dp[x], dp[i] + 1);
		}
	}
	cout << (dp[N] <= K ? "minigimbob" : "water") << "\n";
	return 0;
}
