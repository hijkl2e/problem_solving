#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	vector<int> dp(80001);
	for (int i = 1; i < dp.size(); ++i) {
		dp[i] = dp[i - 1];
		if (i % 3 == 0 || i % 7 == 0) {
			dp[i] += i;
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
