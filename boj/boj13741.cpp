#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	string S;
	getline(cin, S);
	vector<int> dp(S.size(), 1);
	for (int i = 0; i < S.size(); ++i) {
		for (int j = 0; j < i; ++j) {
			if (S[j] < S[i]) {
				dp[i] = max(dp[i], dp[j] + 1);
			}
		}
	}
	int ans = 26 - *max_element(dp.begin(), dp.end());
	cout << ans << "\n";
	return 0;
}
