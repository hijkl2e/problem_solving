#include <bits/stdc++.h>

using namespace std;

vector<int> solve(vector<int> &A) {
	vector<int> dp(A.size(), 1);
	for (int i = 0; i < A.size(); ++i) {
		for (int j = 0; j < i; ++j) {
			if (A[j] < A[i]) {
				dp[i] = max(dp[i], dp[j] + 1);
			}
		}
	}
	return dp;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	vector<int> A(N);
	for (int i = 0; i < N; ++i) {
		cin >> A[i];
	}
	vector<int> dp1 = solve(A);
	reverse(A.begin(), A.end());
	vector<int> dp2 = solve(A);
	int ans{};
	for (int i = 0; i < N; ++i) {
		ans = max(ans, dp1[i] + dp2[N - i - 1] - 1);
	}
	cout << ans << "\n";
	return 0;
}
