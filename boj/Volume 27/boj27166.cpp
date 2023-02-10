#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	ll A{}, B{}, X{}, Y{}, Z{};
	cin >> A >> B >> X >> Y >> Z;
	ll ans = 1e9;
	for (int i = 0, j = 0; j < Z;) {
		ans = min(ans, i + max(Z - j, (Y * Z - A - 1) / B + 1));
		ll x = max((X - A - 1) / B + 1, 1LL);
		A += B++ * x - X;
		i += x;
		j = min(j + x, A / Y);
	}
	cout << ans << "\n";
	return 0;
}
