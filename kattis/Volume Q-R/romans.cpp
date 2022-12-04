#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	double x{};
	cin >> x;
	int ans = lround(x * 1000 * 5280 / 4854);
	cout << ans << "\n";
	return 0;
}
