#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int a{}, b{}, c{}, d{};
	cin >> a >> b >> c >> d;
	int ans = abs(a + b - c - d);
	ans = min(ans, abs(a + c - b - d));
	ans = min(ans, abs(a + d - b - c));
	cout << ans << "\n";
	return 0;
}
