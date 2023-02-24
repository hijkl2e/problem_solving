#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	string S, T;
	getline(cin, S);
	getline(cin, T);
	vector<vector<int>> dp(S.size() + 1, vector<int>(T.size() + 1));
	for (int i = 1; i <= S.size(); ++i) {
		for (int j = 1; j <= T.size(); ++j) {
			if (S[i - 1] == T[j - 1]) {
				dp[i][j] = dp[i - 1][j - 1] + 1;
			} else {
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			}
		}
	}
	string ans;
	int p1 = S.size(), p2 = T.size();
	while (p1 && p2) {
		if (S[p1 - 1] == T[p2 - 1]) {
			ans += S[p1 - 1];
			--p1, --p2;
		} else if (dp[p1 - 1][p2] > dp[p1][p2 - 1]) {
			--p1;
		} else {
			--p2;
		}
	}
	cout << dp.back().back() << "\n";
	if (ans.size()) {
		reverse(ans.begin(), ans.end());
		cout << ans << "\n";
	}
	return 0;
}
