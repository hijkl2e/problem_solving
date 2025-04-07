#include <bits/stdc++.h>

using namespace std;

const double EPS = 1e-9;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int a2{}, a1{}, a0{}, c1{}, c2{}, n0{};
	cin >> a2 >> a1 >> a0 >> c1 >> c2 >> n0;
	bool yes = a2 - c1 >= 0 && c2 - a2 >= 0;
	if (a2 - c1 > 0) {
		int x = a1 * a1 - 4 * (a2 - c1) * a0;
		yes &= x <= 0 || -a1 + sqrt(x) < 2 * n0 * (a2 - c1) + EPS;
	} else if (a2 - c1 == 0) {
		yes &= n0 * a1 >= max(-a0, 0);
	}
	if (c2 - a2 > 0) {
		int x = a1 * a1 + 4 * (c2 - a2) * a0;
		yes &= x <= 0 || a1 + sqrt(x) < 2 * n0 * (c2 - a2) + EPS;
	} else if (c2 - a2 == 0) {
		yes &= n0 * a1 <= min(-a0, 0);
	}
	cout << yes << "\n";
	return 0;
}
