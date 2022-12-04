#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	ll p1{}, t1{}, p2{}, t2{}, H{}, S{};
	cin >> p1 >> t1 >> p2 >> t2 >> H >> S;
	vector<ll> dp(H + 1);
	for (int i = 1; i <= H; ++i) {
		dp[i] = min(dp[max(i - (p1 - S), 0LL)] + t1, dp[max(i - (p2 - S), 0LL)] + t2);
		for (int j = 1; j <= i; ++j) {
			if (j * t1 >= t2) {
				ll dmg = (j - 1) * (p1 - S) + (j * t1 - t2) / t2 * (p2 - S) + (p1 + p2 - S);
				dp[i] = min(dp[i], dp[max(i - dmg, 0LL)] + j * t1);
			}
			if (j * t2 >= t1) {
				ll dmg = (j - 1) * (p2 - S) + (j * t2 - t1) / t1 * (p1 - S) + (p1 + p2 - S);
				dp[i] = min(dp[i], dp[max(i - dmg, 0LL)] + j * t2);
			}
		}
	}
	cout << dp[H] << "\n";
	return 0;
}
