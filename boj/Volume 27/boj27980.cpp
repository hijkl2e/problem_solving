#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, M{};
	cin >> N >> M;
	cin.ignore();
	string s1, s2;
	getline(cin, s1);
	getline(cin, s2);
	vector<vector<int>> dp(M, vector<int>(N));
	for (int i = 0; i < N; ++i) {
		dp[M - 1][i] = s2[M - 1] == s1[i];
	}
	for (int i = M - 2; i >= 0; --i) {
		for (int j = 0; j < N; ++j) {
			dp[i][j] = max(j ? dp[i + 1][j - 1] : -1, j + 1 < N ? dp[i + 1][j + 1] : -1) + (s2[i] == s1[j]);
		}
	}
	int ans = *max_element(dp[0].begin(), dp[0].end());
	cout << ans << "\n";
	return 0;
}
