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
		int maxv{}, minv{};
		maxv = minv = A[i];
		dp[i] = dp[i - 1];
		for (int j = i - 1; j > 0; --j) {
			maxv = max(maxv, A[j]);
			minv = min(minv, A[j]);
			dp[i] = max(dp[i], dp[j - 1] + maxv - minv);
		}
	}
	cout << dp[N] << "\n";
	return 0;
}
