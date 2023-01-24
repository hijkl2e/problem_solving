#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, K{}, x{};
	cin >> N >> K >> x;
	vector<int> A(N);
	vector<int> B(N);
	for (int i = 0; i < N; ++i) {
		cin >> A[i] >> B[i];
	}
	vector<deque<bool>> dp(81, deque<bool>(16001));
	dp[0][0] = true;
	for (int i = 0; i < N; ++i) {
		for (int j = min(i + 1, K); j > 0; --j) {
			for (int k = x * j; k >= A[i]; --k) {
				dp[j][k] |= dp[j - 1][k - A[i]];
			}
		}
	}
	int ans{};
	for (int i = 0; i <= K * x; ++i) {
		if (dp[K][i]) {
			ans = max(ans, i * (K * x - i));
		}
	}
	cout << ans << "\n";
	return 0;
}
