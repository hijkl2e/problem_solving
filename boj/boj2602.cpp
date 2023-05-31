#include <bits/stdc++.h>

using namespace std;

int dp[21][2][101];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	string s1, s2, s3;
	getline(cin, s1);
	getline(cin, s2);
	getline(cin, s3);
	for (int i = 0; i < s2.size(); ++i) {
		if (s2[i] == s1[0]) {
			dp[0][0][i] = 1;
		}
		if (s3[i] == s1[0]) {
			dp[0][1][i] = 1;
		}
	}
	for (int i = 1; i < s1.size(); ++i) {
		for (int j = 0; j < 2; ++j) {
			string &s4 = j ? s3 : s2;
			for (int k = 0; k < s4.size(); ++k) {
				if (s4[k] == s1[i]) {
					for (int l = 0; l < k; ++l) {
						dp[i][j][k] += dp[i - 1][j ^ 1][l];
					}
				}
			}
		}
	}
	int ans{};
	for (int i = 0; i < 2; ++i) {
		for (int j = 0; j < s2.size(); ++j) {
			ans += dp[s1.size() - 1][i][j];
		}
	}
	cout << ans << "\n";
	return 0;
}
