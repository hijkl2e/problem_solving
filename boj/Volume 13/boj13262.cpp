#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ii = pair<int, int>;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, K{};
	cin >> N >> K;
	vector<int> A(N + 1);
	for (int i = 1; i <= N; ++i) {
		cin >> A[i];
	}
	vector<vector<ii>> G(N + 1);
	for (int i = 1; i <= N; ++i) {
		int x{};
		for (int j = i; j > 0; --j) {
			int y = x | A[j];
			if (x != y) {
				G[i].push_back({j, y});
			}
			x = y;
		}
	}
	vector<vector<ll>> dp(2, vector<ll>(N + 1));
	dp[0][0] = 0;
	for (int i = 1; i <= K; ++i) {
		for (int j = i; j <= N - K + i; ++j) {
			for (auto &p : G[j]) {
				dp[1][j] = max(dp[1][j], dp[0][p.first - 1] + p.second);
			}
		}
		copy(dp[1].begin(), dp[1].end(), dp[0].begin());
	}
	cout << dp[0][N] << "\n";
	return 0;
}
