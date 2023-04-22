#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	ll x{}, y{};
	cin >> x >> y;
	string ans(gcd(x, y), '1');
	cout << ans << "\n";
	return 0;
}
