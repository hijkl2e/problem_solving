#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int a{}, b{}, c{}, m{};
	cin >> a >> b >> c >> m;
	int ans{}, x{};
	for (int i = 0; i < 24; ++i) {
		if (x + a <= m) {
			x += a;
			ans += b;
		} else {
			x = max(x - c, 0);
		}
	}
	cout << ans << "\n";
	return 0;
}
