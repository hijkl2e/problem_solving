#include <bits/stdc++.h>

using namespace std;

bool open(char c) {
	return c == '(' || c == '[' || c == '{' || c == '*';
}

bool close(char c) {
	return c == ')' || c == ']' || c == '}' || c == '*';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T{};
	cin >> T;
	cin.ignore();
	while (T--) {
		string S;
		getline(cin, S);
		int n = S.size();
		vector<vector<int>> dp(n, vector<int>(n));
		for (int i = n - 1; i >= 0; --i) {
			dp[i][i] = 1;
			for (int j = i + 1; j < n; ++j) {
				dp[i][j] = min(dp[i + 1][j], dp[i][j - 1]) + 1;
				if (open(S[i]) && close(S[j])
						&& (S[i] == '*' || S[j] == '*' || S[i] / 16 == S[j] / 16)) {
					dp[i][j] = min(dp[i][j], dp[i + 1][j - 1]);
				}
				for (int k = i + 1; k < j; ++k) {
					dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j]);
				}
			}
		}
		cout << dp[0][n - 1] << "\n";
	}
	return 0;
}
