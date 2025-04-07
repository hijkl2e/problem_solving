#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int ans = 5000;
	int x{};
	while (cin >> x) {
		if (x == 1) {
			ans -= 500;
		} else if (x == 2) {
			ans -= 800;
		} else {
			ans -= 1000;
		}
	}
	cout << ans << "\n";
	return 0;
}
