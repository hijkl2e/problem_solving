#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	ll X{}, Y{};
	cin >> X >> Y;
	ll Z = 100 * Y / X;
	if (Z > 98) {
		cout << "-1\n";
		return 0;
	}
	ll ans = ((Z + 1) * X - 100 * Y - 1) / (99 - Z) + 1;
	cout << ans << "\n";
	return 0;
}
