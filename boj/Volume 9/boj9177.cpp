#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T{};
	cin >> T;
	for (int tc = 1; tc <= T; ++tc) {
		string s1, s2, s3;
		cin >> s1 >> s2 >> s3;
		vector<deque<bool>> dp(s1.size() + 1, deque<bool>(s2.size() + 1));
		dp[0][0] = true;
		for (int i = 0; i < dp.size(); ++i) {
			for (int j = 0; j < dp[i].size(); ++j) {
				if (!dp[i][j]) {
					continue;
				}
				if (i + 1 < dp.size() && s1[i] == s3[i + j]) {
					dp[i + 1][j] = true;
				}
				if (j + 1 < dp[i].size() && s2[j] == s3[i + j]) {
					dp[i][j + 1] = true;
				}
			}
		}
		cout << "Data set " << tc << ": " << (dp.back().back() ? "yes" : "no") << "\n";
	}
	return 0;
}
