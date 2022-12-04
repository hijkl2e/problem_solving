#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int x{}, y{};
	while (cin >> x >> y, x || y) {
		bool carry{};
		int ans{};
		while (x || y) {
			carry = x % 10 + y % 10 + carry >= 10;
			ans += carry;
			x /= 10;
			y /= 10;
		}
		cout << ans << "\n";
	}
	return 0;
}
