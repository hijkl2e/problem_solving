#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	ll a{}, b{};
	cin >> a >> b;
	ll ans = a % 2 && b % 2 ? min(a, b) : 0;
	cout << ans << "\n";
	return 0;
}
