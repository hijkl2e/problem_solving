#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9 + 7;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T{};
	cin >> T;
	while (T--) {
		int N{};
		cin >> N;
		vector<int> A(N);
		for (int i = 0; i < N; ++i) {
			cin >> A[i];
		}
		vector<vector<int>> dp(N + 1, vector<int>(501, INF));
		vector<vector<char>> par(N + 1, vector<char>(501));
		dp[N][0] = 0;
		for (int i = N - 1; i >= 0; --i) {
			for (int j = 0; j < 501; ++j) {
				if (dp[i + 1][j] == INF) {
					continue;
				}
				if (j - A[i] >= 0) {
					int &val = dp[i][j - A[i]];
					if (val > dp[i + 1][j]) {
						val = dp[i + 1][j];
						par[i][j - A[i]] = 'U';
					}
				}
				if (j + A[i] < 501) {
					int h = max(dp[i + 1][j], j + A[i]);
					int &val = dp[i][j + A[i]];
					if (val > h) {
						val = h;
						par[i][j + A[i]] = 'D';
					}
				}
			}
		}
		if (dp[0][0] == INF) {
			cout << "IMPOSSIBLE\n";
			continue;
		}
		string ans;
		for (int i = 0, j = 0; i < N; ++i) {
			ans += par[i][j];
			j += (par[i][j] == 'U' ? 1 : -1) * A[i];
		}
		cout << ans << "\n";
	}
	return 0;
}
