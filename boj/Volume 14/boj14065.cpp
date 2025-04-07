#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	double x{};
	cin >> x;
	double ans = 3785411784 / x / 16093440;
	cout << fixed << setprecision(10);
	cout << ans << "\n";
	return 0;
}
