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
	vector<int> dp(N);
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < i; ++j) {
			if (A[j] > A[i]) {
				dp[i] = max(dp[i], dp[j]);
			}
		}
		dp[i] += A[i];
	}
	int ans = *max_element(dp.begin(), dp.end());
	cout << ans << "\n";
	return 0;
}
