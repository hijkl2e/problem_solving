#include <bits/stdc++.h>

using namespace std;

using ll = long long;

ll P, Q;
map<ll, ll> dp;

ll solve(ll x) {
	auto res = dp.insert({x, 0});
	ll &val = res.first->second;
	if (res.second) {
		val = solve(x / P) + solve(x / Q);
	}
	return val;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	ll N{};
	cin >> N >> P >> Q;
	dp[0] = 1;
	cout << solve(N) << "\n";
	return 0;
}
