#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int a{}, b{}, c{};
	cin >> a >> b >> c;
	int ans = a + b - (c == 0 || (a + b) / c > 1 ? 2 * c : 0);
	cout << ans << "\n";
	return 0;
}
