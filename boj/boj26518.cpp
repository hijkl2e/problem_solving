#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	ll b{}, c{};
	cin >> b >> c;
	double ans = (b + sqrt(b * b + 4 * c)) / 2;
	cout << fixed << setprecision(10);
	cout << ans << "\n";
	return 0;
}
