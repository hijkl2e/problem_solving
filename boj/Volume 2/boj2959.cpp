#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int a{}, b{}, c{}, d{};
	cin >> a >> b >> c >> d;
	int ans{};
	ans = max(ans, min(a, b) * min(c, d));
	ans = max(ans, min(a, c) * min(b, d));
	ans = max(ans, min(a, d) * min(b, c));
	cout << ans << "\n";
	return 0;
}
