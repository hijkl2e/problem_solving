#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	vector<int> dp(1001);
	dp[1] = 3;
	for (int i = 2; i < dp.size(); ++i) {
		dp[i] = dp[i - 1];
		for (int j = 0; j < i; ++j) {
			if (gcd(i, j) == 1) {
				dp[i] += 2;
			}
		}
	}
	int T{};
	cin >> T;
	while (T--) {
		int N{};
		cin >> N;
		cout << dp[N] << "\n";
	}
	return 0;
}
