#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	vector<int> dp(10001);
	dp[0] = dp[1] = 1;
	dp[2] = 2;
	for (int i = 3; i < dp.size(); ++i) {
		dp[i] = dp[i - 3] + i / 2 + 1;
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
