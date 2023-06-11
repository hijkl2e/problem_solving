#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, K{};
	cin >> N >> K;
	vector<int> A(N);
	for (int i = 0; i < N; ++i) {
		cin >> A[i];
	}
	vector<int> dp(N);
	for (int i = 0; i < N; ++i) {
		dp[i] = max(i ? dp[i - 1] : 0, 100 * A[i]) - K;
	}
	int ans{};
	for (int i = 0; i < N; ++i) {
		ans = max(ans, dp[i] - 100 * A[i]);
	}
	cout << ans << "\n";
	return 0;
}
