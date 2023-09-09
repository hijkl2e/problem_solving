#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	string S;
	getline(cin, S);
	S = "#" + S;
	vector<int> dp(S.size());
	dp[0] = dp[1] = 1;
	for (int i = 2; i < S.size(); ++i) {
		dp[i] = S[i] == '0' ? 0 : dp[i - 1];
		if (S[i - 1] == '1' || S[i - 1] == '2' || (S[i - 1] == '3' && '0' <= S[i] && S[i] <= '4')) {
			dp[i] += dp[i - 2];
		}
	}
	cout << dp.back() << "\n";
	return 0;
}
