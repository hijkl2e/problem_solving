#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	vector<int> dp(N + 1);
	for (int i = 1; i <= N; ++i) {
		dp[i] = i;
	}
	for (int i = 2; i * i <= N; ++i) {
		int k = i * i;
		for (int j = 0; j + k <= N; ++j) {
			dp[j + k] = min(dp[j + k], dp[j] + 1);
		}
	}
	cout << dp[N] << "\n";
	return 0;
}
