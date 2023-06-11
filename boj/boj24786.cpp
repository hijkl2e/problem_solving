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

deque<bool> sieve() {
	deque<bool> p(1001, true);
	p[0] = p[1] = false;
	for (int i = 2; i < p.size(); ++i) {
		if (p[i]) {
			for (int j = 2 * i; j < p.size(); j += i) {
				p[j] = false;
			}
		}
	}
	return p;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T{};
	cin >> T;
	deque<bool> P = sieve();
	while (T--) {
		ll N{}, E{};
		cin >> N >> E;
		int phi{};
		for (int i = 2; i < N; ++i) {
			if (P[i] && N % i == 0) {
				phi = (i - 1) * (N / i - 1);
				break;
			}
		}
		int ans = mod_inv(E, phi);
		cout << ans << "\n";
	}
	return 0;
}
