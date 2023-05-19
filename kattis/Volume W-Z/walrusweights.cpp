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
	deque<bool> dp(2001);
	dp[0] = true;
	for (int i = 0; i < N; ++i) {
		for (int j = dp.size() - 1; j >= A[i]; --j) {
			dp[j] |= dp[j - A[i]];
		}
	}
	int ans{};
	for (int i = 0;; ++i) {
		if (dp[1000 + i]) {
			ans = 1000 + i;
			break;
		} else if (dp[1000 - i]) {
			ans = 1000 - i;
			break;
		}
	}
	cout << ans << "\n";
	return 0;
}
