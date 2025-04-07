#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9 + 7;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int a{}, b{}, c{}, x{}, y{};
	cin >> a >> b >> c >> x >> y;
	int ans = INF;
	for (int i = 0; i <= x || i <= y; ++i) {
		ans = min(ans, a * max(x - i, 0) + b * max(y - i, 0) + 2 * c * i);
	}
	cout << ans << "\n";
	return 0;
}
