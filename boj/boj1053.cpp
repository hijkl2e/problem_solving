#include <bits/stdc++.h>

using namespace std;

int solve(string &S) {
	vector<vector<int>> dp(S.size(), vector<int>(S.size()));
	for (int i = S.size() - 1; i >= 0; --i) {
		for (int j = i + 1; j < S.size(); ++j) {
			dp[i][j] = min(dp[i + 1][j - 1] + (S[i] != S[j]), min(dp[i + 1][j], dp[i][j - 1]) + 1);
		}
	}
	return dp[0][S.size() - 1];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	string S;
	getline(cin, S);
	int ans = solve(S);
	for (int i = 0; i < S.size(); ++i) {
		for (int j = i + 1; j < S.size(); ++j) {
			swap(S[i], S[j]);
			ans = min(ans, solve(S) + 1);
			swap(S[i], S[j]);
		}
	}
	cout << ans << "\n";
	return 0;
}
