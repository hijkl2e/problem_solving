#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int a{}, b{};
	cin >> a >> b;
	double ans = a * 1.0 / b;
	cout << fixed << setprecision(10);
	cout << ans << "\n";
	return 0;
}
