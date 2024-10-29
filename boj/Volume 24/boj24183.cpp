#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int a{}, b{}, c{};
	cin >> a >> b >> c;
	double ans = (2 * a * 229 * 324 + 2 * b * 297 * 420 + c * 210 * 297) / 1e6;
	cout << fixed << setprecision(10);
	cout << ans << "\n";
	return 0;
}
