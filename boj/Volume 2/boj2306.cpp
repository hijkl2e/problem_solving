#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	string S;
	getline(cin, S);
	int sz = S.size();
	vector<vector<int>> dp(sz + 1, vector<int>(sz));
	for (int i = S.size() - 1; i >= 0; --i) {
		for (int j = i + 1; j < S.size(); ++j) {
			dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
			for (int k = i + 1; k <= j; ++k) {
				if ((S[i] == 'a' && S[k] == 't') || (S[i] == 'g' && S[k] == 'c')) {
					dp[i][j] = max(dp[i][j], dp[i + 1][k - 1] + dp[k + 1][j] + 2);
				}
			}
		}
	}
	cout << dp[0][sz - 1] << "\n";
	return 0;
}
