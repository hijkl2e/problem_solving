#include <bits/stdc++.h>

using namespace std;

const int MOD = 10007;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, M{}, H{};
	cin >> N >> M >> H;
	cin.ignore();
	vector<vector<int>> A(N + 1);
	for (int i = 1; i <= N; ++i) {
		string S;
		getline(cin, S);
		istringstream iss(S);
		int x{};
		while (iss >> x) {
			A[i].push_back(x);
		}
	}
	vector<vector<int>> dp(N + 1, vector<int>(H + 1));
	dp[0][0] = 1;
	for (int i = 1; i <= N; ++i) {
		copy(dp[i - 1].begin(), dp[i - 1].end(), dp[i].begin());
		for (int x : A[i]) {
			for (int j = x; j <= H; ++j) {
				dp[i][j] = (dp[i][j] + dp[i - 1][j - x]) % MOD;
			}
		}
	}
	cout << dp[N][H] << "\n";
	return 0;
}
