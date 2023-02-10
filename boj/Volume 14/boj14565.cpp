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

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	ll N{}, A{};
	cin >> N >> A;
	ll ans = gcd(N, A) == 1 ? mod_inv(A, N) : -1;
	cout << N - A << " " << ans << "\n";
	return 0;
}
