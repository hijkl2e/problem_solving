#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	string s1, s2;
	getline(cin, s1);
	getline(cin, s2);
	vector<vector<int>> dp(s1.size() + 1, vector<int>(s2.size() + 1));
	for (int i = 0; i < s1.size(); ++i) {
		for (int j = 0; j < s2.size(); ++j) {
			if (s1[i] == s2[j]) {
				dp[i + 1][j + 1] = dp[i][j] + 1;
			}
		}
	}
	int ans{};
	for (int i = 0; i < dp.size(); ++i) {
		ans = max(ans, *max_element(dp[i].begin(), dp[i].end()));
	}
	cout << ans << "\n";
	return 0;
}
