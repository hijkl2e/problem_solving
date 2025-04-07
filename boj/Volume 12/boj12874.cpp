#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e9 + 7;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	string S;
	getline(cin, S);
	vector<int> dp1(S.size());
	vector<int> dp2(S.size());
	dp1[0] = 1;
	int ans{};
	for (int i = 0; i < S.size(); ++i) {
		if (S[i] == '(') {
			rotate(dp1.begin(), dp1.end() - 1, dp1.end());
			dp1.front() = 0;
			for (int j = 1; j < S.size(); ++j) {
				dp2[j] = (dp2[j] + dp1[j]) % MOD;
			}
		} else {
			rotate(dp2.begin(), dp2.begin() + 1, dp2.end());
			dp2.back() = 0;
			for (int j = 0; j < S.size() - 1; ++j) {
				dp1[j] = (dp1[j] + dp2[j]) % MOD;
			}
			ans = (ans + dp2[0]) % MOD;
		}
	}
	cout << ans << "\n";
	return 0;
}
