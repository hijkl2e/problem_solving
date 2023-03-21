#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	vector<int> dp(N + 1);
	dp[0] = 1;
	for (int i = 2; i <= N; i += 2) {
		dp[i] = dp[i - 2];
		for (int j = 0; j < i; j += 2) {
			dp[i] += 2 * dp[j];
		}
	}
	cout << dp[N] << "\n";
	return 0;
}
