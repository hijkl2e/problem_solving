#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int sh{};
	double cr{};
	string E;
	while (cin >> E, E != "die") {
		int x{}, y{};
		if (E == "buy") {
			cin >> x >> y;
			cr = (sh * cr + x * y) / (sh + x);
			sh += x;
		} else if (E == "sell") {
			cin >> x >> y;
			sh -= x;
		} else if (E == "split") {
			cin >> x;
			sh *= x;
			cr /= x;
		} else {
			cin >> x;
			sh /= x;
			cr *= x;
		}
	}
	int y{};
	cin >> y;
	double ans = sh * (y - max(y - cr, 0.0) * 0.3);
	cout << fixed << setprecision(10);
	cout << ans << "\n";
	return 0;
}
