#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int a{}, b{}, x{}, y{};
	cin >> a >> b >> x >> y;
	int ans = abs(b - a);
	ans = min(ans, abs(x - a) + abs(b - y));
	ans = min(ans, abs(y - a) + abs(b - x));
	cout << ans << "\n";
	return 0;
}
