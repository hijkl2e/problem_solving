#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	vector<int> A(N);
	for (int i = 0; i < N; ++i) {
		cin >> A[i];
	}
	--N;
	vector<vector<ll>> dp(N, vector<ll>(21));
	dp[0][A[0]] = 1;
	for (int i = 1; i < N; ++i) {
		for (int j = 0; j + A[i] < 21; ++j) {
			dp[i][j + A[i]] += dp[i - 1][j];
		}
		for (int j = 20; j - A[i] >= 0; --j) {
			dp[i][j - A[i]] += dp[i - 1][j];
		}
	}
	cout << dp[N - 1][A[N]] << "\n";
	return 0;
}
