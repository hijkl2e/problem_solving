#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	vector<int> T(N);
	vector<int> P(N);
	for (int i = 0; i < N; ++i) {
		cin >> T[i] >> P[i];
	}
	vector<int> dp(N + 1);
	for (int i = 0; i < N; ++i) {
		dp[i + 1] = max(dp[i + 1], dp[i]);
		if (i + T[i] <= N) {
			dp[i + T[i]] = max(dp[i + T[i]], dp[i] + P[i]);
		}
	}
	cout << dp[N] << "\n";
	return 0;
}
