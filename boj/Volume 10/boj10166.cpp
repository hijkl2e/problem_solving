#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int d1{}, d2{};
	cin >> d1 >> d2;
	vector<int> dp(d2 + 1);
	int ans{};
	for (int i = 1; i <= d2; ++i) {
		dp[i] += i;
		int j = 2 * i;
		for (; j <= d2; j += i) {
			dp[j] -= dp[i];
		}
		if (j - i >= d1 || i >= d1) {
			ans += dp[i];
		}
	}
	cout << ans << "\n";
	return 0;
}
