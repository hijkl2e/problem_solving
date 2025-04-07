#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e6;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	string S;
	getline(cin, S);
	S = "#" + S;
	vector<int> dp(S.size());
	dp[0] = 1;
	for (int i = 1; i < S.size(); ++i) {
		if (S[i] > '0') {
			dp[i] += dp[i - 1];
		}
		if (S[i - 1] == '1' || (S[i - 1] == '2' && S[i] < '7')) {
			dp[i] += dp[i - 2];
		}
		dp[i] %= MOD;
	}
	cout << dp.back() << "\n";
	return 0;
}
