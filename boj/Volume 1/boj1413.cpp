#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, M{};
	cin >> N >> M;
	ll d = 1;
	for (int i = 1; i <= N; ++i) {
		d *= i;
	}
	vector<vector<ll>> dp(N + 1, vector<ll>(M + 1));
	for (int i = 0; i <= N; ++i) {
		for (int j = 1; j < i && j <= M; ++j) {
			for (int k = 1; k <= i; ++k) {
				dp[i][j] += dp[i - k][j - 1] / i;
			}
		}
		for (int j = i; j <= M; ++j) {
			dp[i][j] = d;
		}
	}
	ll n = dp[N][M];
	ll g = gcd(n, d);
	n /= g, d /= g;
	cout << n << "/" << d << "\n";
	return 0;
}
