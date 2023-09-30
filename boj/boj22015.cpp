#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int a{}, b{}, c{};
	cin >> a >> b >> c;
	int ans = 3 * max({a, b, c}) - a - b - c;
	cout << ans << "\n";
	return 0;
}
