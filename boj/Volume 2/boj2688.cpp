#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	vector<vector<ll>> dp(65, vector<ll>(10));
	fill(dp[1].begin(), dp[1].end(), 1);
	for (int i = 2; i < dp.size(); ++i) {
		ll sum{};
		for (int j = 0; j < 10; ++j) {
			sum += dp[i - 1][j];
			dp[i][j] = sum;
		}
	}
	vector<ll> A(65);
	for (int i = 1; i < A.size(); ++i) {
		A[i] = accumulate(dp[i].begin(), dp[i].end(), 0LL);
	}
	int T{};
	cin >> T;
	while (T--) {
		int N{};
		cin >> N;
		cout << A[N] << "\n";
	}
	return 0;
}
