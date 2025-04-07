#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int x{}, y{};
	cin >> x >> y;
	int ans = x > 0 ? y > 0 ? 1 : 4 : y > 0 ? 2 : 3;
	cout << ans << "\n";
	return 0;
}
