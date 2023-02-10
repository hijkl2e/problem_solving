#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	vector<int> A(N + 1);
	for (int i = 1; i <= N; ++i) {
		int s{}, e{};
		cin >> s >> e >> A[i];
	}
	vector<int> dp(N + 1);
	dp[1] = A[1];
	for (int i = 2; i <= N; ++i) {
		dp[i] = max(dp[i - 2] + A[i], dp[i - 1]);
	}
	cout << dp[N] << "\n";
	return 0;
}
