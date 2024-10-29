#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int x{}, y{}, a{}, b{};
	cin >> x >> y >> a >> b;
	if (a > b) {
		swap(x, y);
		swap(a, b);
	}
	for (int i = 0; i < x; ++i) {
		if ((b - a) % x == 0) {
			break;
		}
		b += y;
	}
	int ans = (b - a) % x ? -1 : b;
	cout << ans << "\n";
	return 0;
}
