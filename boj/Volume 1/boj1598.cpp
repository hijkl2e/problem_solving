#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int x{}, y{};
	cin >> x >> y;
	int ans = abs((x - 1) / 4 - (y - 1) / 4) + abs((x - 1) % 4 - (y - 1) % 4);
	cout << ans << "\n";
	return 0;
}
