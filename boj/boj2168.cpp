#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int x{}, y{};
	cin >> x >> y;
	int g = gcd(x, y);
	int ans = g * (x / g + y / g - 1);
	cout << ans << "\n";
	return 0;
}
