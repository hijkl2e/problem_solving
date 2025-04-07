#include <bits/stdc++.h>

using namespace std;

using ll = long long;

ll phi(ll x) {
	ll ret = 1;
	for (ll i = 2; i * i <= x; ++i) {
		ll y = 1;
		while (x % i == 0) {
			x /= i;
			y *= i;
		}
		ret *= y - y / i;
	}
	if (x > 1) {
		ret *= x - 1;
	}
	return ret;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	ll N{};
	cin >> N;
	cout << phi(N) << "\n";
	return 0;
}
