#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const ll MOD = 1e9 + 7;

ll pow(ll x, ll y) {
	ll ret = 1;
	while (y) {
		if (y % 2) {
			ret = ret * x % MOD;
		}
		x = x * x % MOD;
		y /= 2;
	}
	return ret;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	ll K{};
	cin >> K;
	ll ans = (((K + 2) % MOD * pow(2LL, K - 1) % MOD - K - 1) % MOD + MOD) % MOD;
	cout << ans << "\n";
	return 0;
}
