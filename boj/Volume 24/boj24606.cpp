#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int x{}, y{};
	cin >> x >> y;
	int ans = 1;
	while (x || y) {
		if (x % 10 != y % 10) {
			ans *= 2;
		}
		x /= 10;
		y /= 10;
	}
	cout << ans << "\n";
	return 0;
}
