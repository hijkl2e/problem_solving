#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	string S;
	getline(cin, S);
	int n = S.size();
	int ans_x{}, ans_y{}, maxv{};
	for (char c : {'R', 'B'}) {
		vector<int> dp(n);
		vector<int> par(n);
		for (int i = 0; i < n; ++i) {
			if (i && dp[i - 1] >= 0) {
				dp[i] = max(dp[i - 1], 0) + (S[i] == c ? 1 : -1);
				par[i] = par[i - 1];
			} else {
				dp[i] = S[i] == c ? 1 : -1;
				par[i] = i + 1;
			}
		}
		int p = max_element(dp.begin(), dp.end()) - dp.begin();
		if (maxv < dp[p] || (maxv == dp[p] && ans_x > par[p])) {
			maxv = dp[p];
			ans_x = par[p];
			ans_y = p + 1;
		}
	}
	cout << ans_x << " " << ans_y << "\n";
	return 0;
}
