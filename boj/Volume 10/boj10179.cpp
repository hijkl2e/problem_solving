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
		cin >> x;
		x = 0.8 * x + EPS;
		cout << fixed << setprecision(2);
		cout << "$" << x << "\n";
	}
	return 0;
}
