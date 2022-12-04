#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T{};
	cin >> T;
	while (T--) {
		int x{};
		cin >> x;
		int ans{};
		while (x) {
			ans = max(ans, __builtin_popcount(x));
			x /= 10;
		}
		cout << ans << "\n";
	}
	return 0;
}
