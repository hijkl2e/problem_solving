#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9 + 7;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, M{};
	cin >> N >> M;
	vector<int> A(N);
	for (int i = 0; i < N; ++i) {
		cin >> A[i];
	}
	vector<int> dp(N + 1, INF);
	dp[0] = 0;
	for (int i = 0; i < N; ++i) {
		int sum = -1;
		for (int j = i; j >= 0; --j) {
			sum += A[j] + 1;
			if (sum > M) {
				break;
			}
			dp[i + 1] = min(dp[i + 1], dp[j] + (M - sum) * (M - sum));
		}
	}
	int ans = INF, sum = -1;
	for (int i = N - 1; i >= 0; --i) {
		sum += A[i] + 1;
		if (sum > M) {
			break;
		}
		ans = min(ans, dp[i]);
	}
	cout << ans << "\n";
	return 0;
}
