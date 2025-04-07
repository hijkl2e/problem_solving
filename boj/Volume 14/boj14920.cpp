#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int x{};
	cin >> x;
	int ans = 1;
	while (x > 1) {
		if (x % 2) {
			x = 3 * x + 1;
		} else {
			x /= 2;
		}
		++ans;
	}
	cout << ans << "\n";
	return 0;
}
