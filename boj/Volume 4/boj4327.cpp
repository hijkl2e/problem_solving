#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int a{}, b{}, c{}, d{};
	while (cin >> a >> b >> c >> d, b || c) {
		int ans = 120;
		ans += (a - b + 40) % 40;
		ans += (c - b + 40) % 40;
		ans += (c - d + 40) % 40;
		ans *= 9;
		cout << ans << "\n";
	}
	return 0;
}
