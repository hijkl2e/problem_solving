#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	ll sm{}, xr{};
	int M{};
	cin >> M;
	while (M--) {
		int q{}, x{};
		cin >> q;
		if (q < 3) {
			cin >> x;
			sm += (3 - 2 * q) * x;
			xr ^= x;
		} else {
			cout << (q == 3 ? sm : xr) << "\n";
		}
	}
	return 0;
}
