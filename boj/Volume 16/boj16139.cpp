#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	string S;
	getline(cin, S);
	vector<vector<int>> dp(26, vector<int>(S.size() + 1));
	for (int i = 0; i < 26; ++i) {
		for (int j = 1; j <= S.size(); ++j) {
			dp[i][j] = dp[i][j - 1] + (S[j - 1] == ('a' + i));
		}
	}
	int Q{};
	cin >> Q;
	while (Q--) {
		char c{};
		int l{}, r{};
		cin >> c >> l >> r;
		int ans = dp[c - 'a'][r + 1] - dp[c - 'a'][l];
		cout << ans << "\n";
	}
	return 0;
}
