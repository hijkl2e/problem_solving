#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int x{}, y{}, w{}, h{};
	cin >> x >> y >> w >> h;
	int ans = min({x, w - x, y, h - y});
	cout << ans << "\n";
	return 0;
}
