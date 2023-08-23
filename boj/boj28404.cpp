#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	vector<ll> fibo(87);
	fibo[1] = 1;
	fibo[2] = 2;
	for (int i = 3; i < fibo.size(); ++i) {
		fibo[i] = fibo[i - 1] + fibo[i - 2];
	}
	map<ll, ll> dp;
	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 3;
	dp[9227465] = -1;
	for (int i = 4; i < fibo.size(); ++i) {
		if (dp[i]) {
			continue;
		}
		int j = i + (i == 4 ? 2 : 1);
		while (dp[j]) {
			++j;
		}
		ll x = i, y = j;
		while (x < fibo.size()) {
			dp[x] = y;
			tie(x, y) = make_pair(y, fibo[x]);
		}
		dp[x] = y;
		dp[y] = -1;
	}
	vector<ll> A;
	for (auto &p : dp) {
		A.push_back(p.first);
	}
	int T{};
	cin >> T;
	while (T--) {
		ll N{};
		cin >> N;
		if (dp[N]) {
			cout << dp[N] << "\n";
			continue;
		}
		int p = lower_bound(A.begin(), A.end(), N) - A.begin();
		if ((p + N) % 2) {
			ll ans = N + (dp[N + 1] ? 2 : 1);
			cout << ans << "\n";
		} else {
			cout << "-1\n";
		}
	}
	return 0;
}
