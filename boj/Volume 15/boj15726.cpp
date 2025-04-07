#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	ll a{}, b{}, c{};
	cin >> a >> b >> c;
	if (b < c) {
		swap(b, c);
	}
	ll ans = a * b / c;
	cout << ans << "\n";
	return 0;
}
