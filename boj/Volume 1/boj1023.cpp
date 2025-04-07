#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	ll N{}, K{};
	cin >> N >> K;
	if (N % 2) {
		string ans = string(N, '(');
		for (int i = 0; i < N; ++i) {
			if (K & (1LL << i)) {
				ans[N - i - 1] = ')';
			}
		}
		cout << ans << "\n";
		return 0;
	}
	vector<vector<ll>> dp(N / 2 + 1, vector<ll>(N / 2 + 1));
	dp[0][0] = 1;
	for (int i = 1; i <= N / 2; ++i) {
		dp[i][0] = 1;
		for (int j = 1; j <= i; ++j) {
			dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
		}
	}
	if (K >= (1LL << N) - dp[N / 2][N / 2]) {
		cout << "-1\n";
		return 0;
	}
	int a{}, b{};
	bool f = true;
	string ans = string(N, '(');
	for (int i = 0; i < N; ++i) {
		ll cnt = (1LL << (N - i - 1)) - (f && a < N / 2 ? dp[N / 2 - b][N / 2 - a - 1] : 0);
		if (K < cnt) {
			++a;
		} else {
			ans[i] = ')';
			K -= cnt;
			++b;
		}
		f &= a >= b;
	}
	cout << ans << "\n";
	return 0;
}
