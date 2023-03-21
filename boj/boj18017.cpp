#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	double a{}, b{};
	cin >> a >> b;
	double ans = (a + b) / (1 + a * b / 89875517873681764LL);
	cout << fixed << setprecision(10);
	cout << ans << "\n";
	return 0;
}
