#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	cin.ignore();
	string S;
	getline(cin, S);
	vector<int> A;
	for (int i = 0, j = 1; i < N; i = j++) {
		while (j < N && S[i] == S[j]) {
			++j;
		}
		A.push_back(S[i] == 'R' ? 1 : S[i] == 'G' ? 2 : 3);
	}
	N = A.size();
	vector<vector<int>> dp(N + 1, vector<int>(N));
	for (int i = N - 1; i >= 0; --i) {
		for (int j = i + 1; j < N; ++j) {
			dp[i][j] = dp[i + 1][j];
			for (int k = i + 1; k <= j; ++k) {
				if (A[i] == A[k]) {
					dp[i][j] = max(dp[i][j], dp[i + 1][k - 1] + dp[k][j] + 1);
				}
			}
		}
	}
	int ans = N - dp[0][N - 1];
	cout << ans << "\n";
	return 0;
}
