#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	vector<int> A(N + 1);
	for (int i = 1; i <= N; ++i) {
		cin >> A[i];
	}
	vector<int> dp(N + 1);
	for (int i = 1; i <= N; ++i) {
		dp[i] = max(dp[i - 1], 0) + A[i];
	}
	int ans = *max_element(dp.begin() + 1, dp.end());
	cout << ans << "\n";
	return 0;
}
