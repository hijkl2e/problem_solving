#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int A{}, K{};
	cin >> A >> K;
	vector<int> dp(K + 1, 1e9);
	dp[A] = 0;
	for (int i = A; i < K; ++i) {
		dp[i + 1] = min(dp[i + 1], dp[i] + 1);
		if (2 * i <= K) {
			dp[2 * i] = min(dp[2 * i], dp[i] + 1);
		}
	}
	cout << dp[K] << "\n";
	return 0;
}
