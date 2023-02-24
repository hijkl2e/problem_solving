#include <bits/stdc++.h>

using namespace std;

vector<string> S(4);
vector<vector<int>> dp(4, vector<int>(17001));

void solve(int k, int x1, int x2, int y1, int y2) {
	for (int i = y1 - 1; i < y2; ++i) {
		dp[k][i] = i - y1 + 1;
	}
	for (int i = x1; i < x2; ++i) {
		dp[k + 1][y1 - 1] = i - x1 + 1;
		for (int j = y1; j < y2; ++j) {
			if (S[k][i] == S[k + 1][j]) {
				dp[k + 1][j] = dp[k][j - 1];
			} else {
				dp[k + 1][j] = min({dp[k][j - 1], dp[k][j], dp[k + 1][j - 1]}) + 1;
			}
		}
		copy(dp[k + 1].begin() + y1 - 1, dp[k + 1].begin() + y2, dp[k].begin() + y1 - 1);
	}
}

void solve(int x1, int x2, int y1, int y2) {
	if (x1 == x2) {
		for (int i = y1; i < y2; ++i) {
			cout << "a " << S[1][i] << "\n";
		}
		return;
	} else if (x1 + 1 == x2) {
		if (y1 == y2) {
			cout << "d " << S[0][x1] << "\n";
			return;
		}
		int z = -1;
		for (int i = y1; i < y2; ++i) {
			if (S[0][x1] == S[1][i]) {
				z = i;
				break;
			}
		}
		for (int i = y1; i < y2; ++i) {
			cout << (z == -1 && i == y1 ? "m" : i == z ? "c" : "a") << " " << S[1][i] << "\n";
		}
		return;
	}
	int x3 = (x1 + x2) / 2;
	solve(0, x1, x3, y1, y2);
	solve(2, S[0].size() - x2 + 1, S[0].size() - x3 + 1, S[1].size() - y2 + 1, S[1].size() - y1 + 1);
	int y3 = y1 - 1;
	for (int i = y1; i < y2; ++i) {
		if (dp[0][y3] + dp[2][S[1].size() - y3 - 1] > dp[0][i] + dp[2][S[1].size() - i - 1]) {
			y3 = i;
		}
	}
	++y3;
	solve(x1, x3, y1, y3);
	solve(x3, x2, y3, y2);
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
	solve(1, S[0].size(), 1, S[1].size());
	return 0;
}
