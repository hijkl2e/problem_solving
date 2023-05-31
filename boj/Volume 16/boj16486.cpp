#include <bits/stdc++.h>

using namespace std;

const double PI = 3.141592;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int d1{}, d2{};
	cin >> d1 >> d2;
	double ans = 2 * (d1 + PI * d2);
	cout << fixed << setprecision(10);
	cout << ans << "\n";
	return 0;
}
