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
		int x{}, t{}, c{};
		cin >> x >> t >> c;
		t2c[t - x] += c;
	}
	ll ans{};
	for (auto &p : t2c) {
		ans = max(ans, p.second);
	}
	cout << ans << "\n";
	return 0;
}
