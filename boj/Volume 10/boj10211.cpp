#include <bits/stdc++.h>

using namespace std;

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
		vector<int> dp(N);
		dp[0] = A[0];
		for (int i = 1; i < N; ++i) {
			dp[i] = max(dp[i - 1], 0) + A[i];
		}
		int ans = *max_element(dp.begin(), dp.end());
		cout << ans << "\n";
	}
	return 0;
}
