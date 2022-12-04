#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	map<int, int> i2d;
	ll ans{};
	while (N--) {
		int x{};
		cin >> x;
		int d{};
		auto it = i2d.upper_bound(x);
		if (it != i2d.end()) {
			d = it->second + 1;
		}
		if (it != i2d.begin()) {
			--it;
			d = max(d, it->second + 1);
		}
		i2d[x] = d;
		ans += d;
		cout << ans << "\n";
	}
	return 0;
}
