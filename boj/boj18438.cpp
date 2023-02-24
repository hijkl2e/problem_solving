#include <bits/stdc++.h>

using namespace std;

vector<string> S(4);
vector<vector<int>> dp(4, vector<int>(7001));

void solve(int k, int x1, int x2, int y1, int y2) {
	for (int i = 0; i < 2; ++i) {
		fill(dp[k + i].begin() + y1 - 1, dp[k + i].begin() + y2, 0);
	}
	for (int i = x1; i < x2; ++i) {
		for (int j = y1; j < y2; ++j) {
			if (S[k][i] == S[k + 1][j]) {
				dp[k + 1][j] = dp[k][j - 1] + 1;
			} else {
				dp[k + 1][j] = max(dp[k][j], dp[k + 1][j - 1]);
			}
		}
		copy(dp[k + 1].begin() + y1, dp[k + 1].begin() + y2, dp[k].begin() + y1);
	}
}

string solve(int x1, int x2, int y1, int y2) {
	if (x1 == x2) {
		return "";
	} else if (x1 + 1 == x2) {
		for (int i = y1; i < y2; ++i) {
			if (S[0][x1] == S[1][i]) {
				return S[1].substr(i, 1);
			}
		}
		return "";
	}
	int x3 = (x1 + x2) / 2;
	solve(0, x1, x3, y1, y2);
	solve(2, S[0].size() - x2 + 1, S[0].size() - x3 + 1, S[1].size() - y2 + 1, S[1].size() - y1 + 1);
	int y3 = y1 - 1;
	for (int i = y1; i < y2; ++i) {
		if (dp[0][y3] + dp[2][S[1].size() - y3 - 1] < dp[0][i] + dp[2][S[1].size() - i - 1]) {
			y3 = i;
		}
	}
	++y3;
	return solve(x1, x3, y1, y3) + solve(x3, x2, y3, y2);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	getline(cin, S[0]);
	getline(cin, S[1]);
	S[0] = "#" + S[0];
	S[1] = "#" + S[1];
	S[2] = S[0], S[3] = S[1];
	reverse(S[2].begin() + 1, S[2].end());
	reverse(S[3].begin() + 1, S[3].end());
	string ans = solve(1, S[0].size(), 1, S[1].size());
	cout << ans.size() << "\n";
	cout << ans << "\n";
	return 0;
}
