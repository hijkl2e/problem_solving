#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int a{}, b{}, c{}, d{}, e{};
	cin >> a >> b >> c >> d >> e;
	int ans{};
	if (a < 0) {
		ans = b * e + d - c * a;
	} else {
		ans = (b - a) * e;
	}
	cout << ans << "\n";
	return 0;
}
