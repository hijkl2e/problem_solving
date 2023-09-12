#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, M{};
	cin >> N >> M;
	vector<int> dp(M + 1);
	dp[0] = N;
	for (int i = 0; i < M; ++i) {
		for (int j = 1; j < 7 && i + j <= M; j += 2) {
			dp[i + j] = max(dp[i + j], dp[i] + dp[i] * (j == 1 ? 5 : j == 3 ? 20 : 35) / 100);
		}
	}
	cout << dp[M] << "\n";
	return 0;
}
