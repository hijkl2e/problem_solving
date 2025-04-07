#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	vector<int> A(N);
	for (int i = 0; i < N; ++i) {
		cin >> A[i];
	}
	sort(A.begin(), A.end());
	vector<vector<int>> dp(N, vector<int>(N, 2));
	for (int i = N - 1; i > 0; --i) {
		int p1 = i - 1, p2 = i + 1;
		while (0 <= p1 && p2 < N) {
			if (A[p1] + A[p2] > 2 * A[i]) {
				--p1;
			} else if (A[p1] + A[p2] < 2 * A[i]) {
				++p2;
			} else {
				dp[p1--][i] = dp[i][p2] + 1;
			}
		}
	}
	int ans{};
	for (int i = 0; i < N; ++i) {
		ans = max(ans, *max_element(dp[i].begin(), dp[i].end()));
	}
	ans = min(ans, N);
	cout << ans << "\n";
	return 0;
}
