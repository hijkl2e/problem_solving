#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	vector<int> P(N + 1);
	for (int i = 1; i <= N; ++i) {
		cin >> P[i];
	}
	vector<int> dp(N + 1, 1e9);
	dp[0] = 0;
	for (int i = 1; i <= N; ++i) {
		for (int j = i; j <= N; ++j) {
			dp[j] = min(dp[j], dp[j - i] + P[i]);
		}
	}
	cout << dp[N] << "\n";
	return 0;
}
