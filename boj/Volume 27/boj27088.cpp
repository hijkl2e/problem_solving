#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9 + 7;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, K{};
	cin >> N >> K;
	vector<int> X(N + 1);
	vector<int> Y(N + 1);
	cin >> X[0] >> Y[0];
	for (int i = 1; i <= N; ++i) {
		int s{};
		cin >> X[i] >> Y[i] >> s;
		X[i] -= X[0];
		Y[i] -= Y[0];
		if (s / 2) {
			swap(X[i], Y[i]);
		}
		if (s % 2 == 0) {
			X[i] = -X[i];
		}
	}
	vector<int> A(N + 1);
	vector<int> B(N + 1);
	for (int i = 1; i <= N; ++i) {
		int x = X[i], y = abs(Y[i]);
		A[i] = max(y - x, 0);
		B[i] = y + max(x, y);
	}
	vector<int> dp(2001, INF);
	dp[0] = 0;
	for (int i = 1; i <= N; ++i) {
		for (int j = dp.size() - 1; j >= B[i]; --j) {
			dp[j] = min(dp[j], dp[j - B[i]] + A[i]);
		}
	}
	int ans = INF;
	for (int i = 1; i <= N; ++i) {
		ans = min(ans, A[i] + max(K - B[i], 0));
	}
	for (int i = 1; i < dp.size(); ++i) {
		ans = min(ans, dp[i] + max(K - i, 0));
	}
	cout << ans << "\n";
	return 0;
}
