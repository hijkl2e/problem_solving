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
	cout << dp.back().back() << "\n";
	return 0;
}
