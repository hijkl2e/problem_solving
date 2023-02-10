#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, A{}, L{};
	cin >> N >> A >> L;
	vector<int> X(N);
	vector<int> Y(N);
	for (int i = 0; i < N; ++i) {
		cin >> X[i] >> Y[i];
	}
	vector<vector<int>> dp(N + 1, vector<int>(L + 1, -1));
	vector<deque<bool>> par(N + 1, deque<bool>(L + 1));
	dp[0][L] = A;
	for (int i = 0; i < N; ++i) {
		for (int j = 1; j <= L; ++j) {
			if (dp[i][j] == -1) {
				continue;
			}
			if (X[i] != -1) {
				int val = max(dp[i][j] - X[i], Y[i] == -1 ? 0 : -1);
				if (dp[i + 1][j] < val) {
					dp[i + 1][j] = val;
					par[i + 1][j] = true;
				}
			}
			if (Y[i] != -1 && j > Y[i] && dp[i + 1][j - Y[i]] < dp[i][j]) {
				dp[i + 1][j - Y[i]] = dp[i][j];
				par[i + 1][j - Y[i]] = false;
			}
		}
	}
	int x{};
	for (int i = 1; i <= L; ++i) {
		if (dp[N][i] != -1) {
			x = i;
			break;
		}
	}
	if (x == 0) {
		cout << "NO\n";
		return 0;
	}
	cout << "YES\n";
	string ans;
	for (int i = N - 1; i >= 0; --i) {
		if (par[i + 1][x]) {
			ans += "A";
		} else {
			ans += "L";
			x += Y[i];
		}
	}
	reverse(ans.begin(), ans.end());
	cout << ans << "\n";
	return 0;
}
