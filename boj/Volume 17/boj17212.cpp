#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	vector<int> A{1, 2, 5, 7};
	vector<int> dp(N + 1, 1e9);
	dp[0] = 0;
	for (int i = 1; i <= N; ++i) {
		for (int x : A) {
			if (i - x < 0) {
				break;
			}
			dp[i] = min(dp[i], dp[i - x] + 1);
		}
	}
	cout << dp[N] << "\n";
	return 0;
}
