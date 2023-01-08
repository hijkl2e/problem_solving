#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	map<int, int> i2d;
	i2d[0] = i2d[N + 1] = -1;
	ll ans{};
	while (N--) {
		int x{};
		cin >> x;
		auto it = i2d.upper_bound(x);
		int d = max(it->second, prev(it)->second) + 1;
		i2d.insert(it, {x, d});
		ans += d;
		cout << ans << "\n";
	}
	return 0;
}
