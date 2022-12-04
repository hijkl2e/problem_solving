#include <bits/stdc++.h>

using namespace std;

using ll = long long;

ll solve(ll x) {
	ll ret{};
	for (ll i = 1; i <= x;) {
		ll j = x / (x / i);
		if ((j - i) % 2 == 0) {
			ret += x / i * (i % 2 ? -1 : 1);
		}
		i = j + 1;
	}
	return ret;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	ll S{}, T{};
	cin >> S >> T;
	ll ans = solve(T) - solve(S - 1);
	cout << ans << "\n";
	return 0;
}
