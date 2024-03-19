#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int x{}, y{};
	char c{};
	while (cin >> x >> c >> y, !(x == 0 && c == 'W' && y == 0)) {
		int ans = x + (c == 'W' ? -1 : 1) * y;
		if (ans < -200) {
			cout << "Not allowed\n";
		} else {
			cout << ans << "\n";
		}
	}
	return 0;
}
