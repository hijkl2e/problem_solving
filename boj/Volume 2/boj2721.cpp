#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	vector<int> dp(301);
	for (int i = 1; i < dp.size(); ++i) {
		dp[i] = dp[i - 1] + i * (i + 1) * (i + 2) / 2;
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
