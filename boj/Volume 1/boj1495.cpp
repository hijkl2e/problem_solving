#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, S{}, M{};
	cin >> N >> S >> M;
	vector<int> A(N);
	for (int i = 0; i < N; ++i) {
		cin >> A[i];
	}
	vector<deque<bool>> dp(N + 1, deque<bool>(M + 1));
	dp[0][S] = true;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j <= M; ++j) {
			if (!dp[i][j]) {
				continue;
			}
			if (j + A[i] <= M) {
				dp[i + 1][j + A[i]] = true;
			}
			if (j - A[i] >= 0) {
				dp[i + 1][j - A[i]] = true;
			}
		}
	}
	int ans = -1;
	for (int i = M; i >= 0; --i) {
		if (dp[N][i]) {
			ans = i;
			break;
		}
	}
	cout << ans << "\n";
	return 0;
}
