#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9 + 7;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	vector<int> H(N);
	for (int i = 0; i < N; ++i) {
		cin >> H[i];
	}
	int sum = accumulate(H.begin(), H.end(), 0);
	int minv = max((sum - N * (N - 1) / 2 - 1) / N, 0);
	sum -= N * minv;
	vector<vector<int>> dp[100];
	for (int i = 0; i < N; ++i) {
		dp[i].assign(101, vector<int>(sum + 1, INF));
	}
	for (int i = 1; i < 101 && i <= sum; ++i) {
		dp[0][i][i] = abs(H[0] - (minv + i));
	}
	for (int i = 1; i < N; ++i) {
		for (int j = 1; j < 101; ++j) {
			for (int k = j; k <= sum; ++k) {
				for (int l = -1; l < 2; ++l) {
					if (j + l == 0 || j + l == 101) {
						continue;
					}
					dp[i][j][k] = min(dp[i][j][k], dp[i - 1][j + l][k - j]);
				}
				dp[i][j][k] += abs(H[i] - (minv + j));
			}
		}
	}
	int ans = INF;
	for (int i = 1; i < 101; ++i) {
		ans = min(ans, dp[N - 1][i][sum]);
	}
	ans /= 2;
	cout << ans << "\n";
	return 0;
}
