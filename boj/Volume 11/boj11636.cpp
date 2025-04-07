#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T{};
	cin >> T;
	while (T--) {
		int prev_x = 1;
		int x{}, ans{};
		while (cin >> x, x) {
			ans += max(x - 2 * prev_x, 0);
			prev_x = x;
		}
		cout << ans << "\n";
	}
	return 0;
}
