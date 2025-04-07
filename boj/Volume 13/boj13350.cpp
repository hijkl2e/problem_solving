#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9 + 7;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	vector<int> A(N);
	vector<int> B(N);
	for (int i = 0; i < N; ++i) {
		int c{}, f{}, u{};
		cin >> A[i] >> c >> f >> u;
		B[i] = c + u > f ? max((c + f + u) / 2 - c + 1, 0) : INF;
	}
	int sum = accumulate(A.begin(), A.end(), 0);
	vector<int> dp(sum + 1, INF);
	dp[0] = 0;
	for (int i = 0; i < N; ++i) {
		for (int j = sum; j >= A[i]; --j) {
			dp[j] = min(dp[j], dp[j - A[i]] + B[i]);
		}
	}
	int ans = INF;
	for (int i = sum / 2 + 1; i <= sum; ++i) {
		ans = min(ans, dp[i]);
	}
	if (ans == INF) {
		cout << "impossible\n";
	} else {
		cout << ans << "\n";
	}
	return 0;
}
