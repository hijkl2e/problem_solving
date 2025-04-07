#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int x{}, y{};
	cin >> x >> y;
	string ans;
	if (x == 1 || (x == 2 && y < 18)) {
		ans = "Before";
	} else if (x == 2 && y == 18) {
		ans = "Special";
	} else {
		ans = "After";
	}
	cout << ans << "\n";
	return 0;
}
