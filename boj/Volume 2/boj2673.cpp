#include <bits/stdc++.h>

using namespace std;

using ii = pair<int, int>;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	vector<ii> A(N);
	for (auto &[u, v] : A) {
		cin >> u >> v;
		--u, --v;
		if (u > v) {
			swap(u, v);
		}
	}
	vector<deque<bool>> B(100, deque<bool>(100));
	for (auto &[u, v] : A) {
		B[u][v] = true;
	}
	vector<vector<int>> dp(100, vector<int>(100));
	for (int l = 1; l < 100; ++l) {
		for (int i = 0; i + l < 100; ++i) {
			int j = i + l;
			dp[i][j] = dp[i + 1][j - 1] + B[i][j];
			for (int k = i; k < j; ++k) {
				dp[i][j] = max(dp[i][j], dp[i][k] + dp[k + 1][j]);
			}
		}
	}
	cout << dp[0][99] << "\n";
	return 0;
}
