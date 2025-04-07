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
	int M{};
	cin >> M;
	ll ans{};
	while (M--) {
		ll N{}, S{};
		cin >> N >> S;
		ans = (ans + S * pow(N, MOD - 2)) % MOD;
	}
	cout << ans << "\n";
	return 0;
}
