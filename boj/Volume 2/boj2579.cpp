#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	vector<int> A(N + 2);
	for (int i = 1; i <= N; ++i) {
		cin >> A[i];
	}
	vector<int> dp(N + 2);
	dp[1] = A[1];
	dp[2] = A[1] + A[2];
	for (int i = 3; i <= N; ++i) {
		dp[i] = max(dp[i - 2], dp[i - 3] + A[i - 1]) + A[i];
	}
	cout << dp[N] << "\n";
	return 0;
}
