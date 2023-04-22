#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int a{}, b{}, c{}, d{}, p{};
	cin >> a >> b >> c >> d >> p;
	int ans = min(a * p, b + d * max(p - c, 0));
	cout << ans << "\n";
	return 0;
}
