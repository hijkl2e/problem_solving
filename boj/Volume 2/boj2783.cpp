#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int x{}, y{};
	cin >> x >> y;
	double ans = x * 1000.0 / y;
	int N{};
	cin >> N;
	while (N--) {
		cin >> x >> y;
		ans = min(ans, x * 1000.0 / y);
	}
	cout << fixed << setprecision(10);
	cout << ans << "\n";
	return 0;
}
