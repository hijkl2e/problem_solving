#include <bits/stdc++.h>

using namespace std;

using ll = long long;

pair<ll, ll> ext_gcd(ll a, ll b) {
	if (b) {
		auto [x, y] = ext_gcd(b, a % b);
		return {y, x - (a / b) * y};
	} else {
		return {1, 0};
	}
}

ll mod_inv(ll a, ll mod) {
	return (ext_gcd(a, mod).first + mod) % mod;
}
