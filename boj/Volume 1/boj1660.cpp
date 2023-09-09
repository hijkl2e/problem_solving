#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	vector<int> A(121);
	for (int i = 1; i < A.size(); ++i) {
		A[i] = A[i - 1] + i * (i + 1) / 2;
	}
	vector<int> dp(N + 1, 1e9);
	dp[0] = 0;
	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j < A.size() && i - A[j] >= 0; ++j) {
			dp[i] = min(dp[i], dp[i - A[j]] + 1);
		}
	}
	cout << dp[N] << "\n";
	return 0;
}
