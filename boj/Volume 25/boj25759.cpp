#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9 + 7;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	vector<int> A(N);
	for (int i = 0; i < N; ++i) {
		cin >> A[i];
	}
	vector<int> dp(101, -INF);
	dp[A[0]] = 0;
	for (int i : A) {
		for (int j = 1; j < 101; ++j) {
			if (dp[j] == -INF) {
				continue;
			}
			dp[i] = max(dp[i], dp[j] + (j - i) * (j - i));
		}
	}
	int ans{};
	for (int i = 1; i < 101; ++i) {
		ans = max(ans, dp[i]);
	}
	cout << ans << "\n";
	return 0;
}
