#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const double EPS = 1e-12;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	ll x{};
	cin >> x;
	cout << fixed << setprecision(10);
	ll ans = x ? sqrtl(x - 1) + 1 + EPS : 0;
	cout << ans << "\n";
	return 0;
}
