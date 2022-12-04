#include <bits/stdc++.h>

using namespace std;

using ll = long long;

ll P;
vector<ll> fact;

ll pow(ll x, ll y) {
	ll ret = 1;
	while (y) {
		if (y % 2) {
			ret = ret * x % P;
		}
		x = x * x % P;
		y /= 2;
	}
	return ret;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N >> P;
	fact.resize(N + 1);
	fact[0] = 1;
	for (int i = 1; i <= N; ++i) {
		fact[i] = fact[i - 1] * i % P;
	}
	vector<vector<ll>> dp((N - 1) / 2);
	for (int i = 0; i < dp.size(); ++i) {
		dp[i].resize(i + 1);
		dp[i][0] = dp[i][i] = 1;
		for (int j = 1; j < i; ++j) {
			dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j]) % P;
		}
	}
	ll ans = N % 2 ? 0 : fact[N - 2];
	for (int i = 0; i < dp.size(); ++i) {
		ll sum{};
		for (int j = 0; j <= i; ++j) {
			sum += dp[i][j] * fact[N - i + j - 3] % P;
		}
		ans += sum * (i + 2 - N % 2) % P;
	}
	ans = N * ans % P;
	cout << ans << "\n";
	return 0;
}
