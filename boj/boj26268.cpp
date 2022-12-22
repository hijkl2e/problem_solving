#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	map<ll, ll> t2c;
	while (N--) {
		ll x{}, t{}, c{};
		cin >> x >> t >> c;
		ll val = c;
		auto it = t2c.upper_bound(t - x);
		if (it != t2c.begin()) {
			val += (--it)->second;
		}
		it = ++t2c.insert_or_assign(t - x, val).first;
		while (it != t2c.end()) {
			if (it->second > val) {
				break;
			}
			it = t2c.erase(it);
		}
	}
	ll ans{};
	for (auto &p : t2c) {
		ans = max(ans, p.second);
	}
	cout << ans << "\n";
	return 0;
}
