#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	vector<int> dp(31);
	dp[0] = 1;
	for (int i = 2; i < 31; i += 2) {
		dp[i] = dp[i - 2];
		for (int j = 0; j < i; j += 2) {
			dp[i] += 2 * dp[j];
		}
	}
	int N{};
	while (cin >> N, N != -1) {
		cout << dp[N] << "\n";
	}
	return 0;
}
