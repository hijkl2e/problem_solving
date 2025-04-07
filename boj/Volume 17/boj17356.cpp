#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int a{}, b{};
	cin >> a >> b;
	double ans = 1 / (1 + pow(10, (b - a) / 400.0));
	cout << fixed << setprecision(10);
	cout << ans << "\n";
	return 0;
}
