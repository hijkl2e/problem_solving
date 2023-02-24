#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	ll N{}, B{}, C{};
	cin >> N >> B >> C;
	vector<int> A(N + 2);
	for (int i = 2; i < N + 2; ++i) {
		cin >> A[i];
	}
	if (B <= C) {
		ll ans = B * accumulate(A.begin(), A.end(), 0LL);
		cout << ans << "\n";
		return 0;
	}
	vector<vector<int>> dp(N + 2, vector<int>(3));
	for (int i = 2; i < N + 2; ++i) {
		for (int j = 0; j < 2; ++j) {
			int minv = min(dp[i - 1][j], A[i]);
			dp[i - 1][j] -= minv, A[i] -= minv;
			dp[i][j + 1] = minv;
		}
		dp[i][0] = A[i];
	}
	ll ans{};
	for (int i = 2; i < N + 2; ++i) {
		for (int j = 0; j < 3; ++j) {
			ans += (B + j * C) * dp[i][j];
		}
	}
	cout << ans << "\n";
	return 0;
}
