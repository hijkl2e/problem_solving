#include <bits/stdc++.h>

using namespace std;

const double EPS = 1e-9;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T{};
	cin >> T;
	while (T--) {
		double x{};
		string s;
		cin >> x >> s;
		if (s == "kg") {
			x *= 2.2046;
			s = "lb";
		} else if (s == "lb") {
			x *= 0.4536;
			s = "kg";
		} else if (s == "l") {
			x *= 0.2642;
			s = "g";
		} else {
			x *= 3.7854;
			s = "l";
		}
		x += EPS;
		cout << fixed << setprecision(4);
		cout << x << " " << s << "\n";
	}
	return 0;
}
