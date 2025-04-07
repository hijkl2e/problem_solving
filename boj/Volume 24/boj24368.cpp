#include <bits/stdc++.h>

using namespace std;

const double EPS = 1e-9;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int a2{}, a1{}, a0{}, c{}, n0{};
	cin >> a2 >> a1 >> a0 >> c >> n0;
	bool yes{};
	if (c - a2 > 0) {
		int x = a1 * a1 + 4 * (c - a2) * a0;
		yes = x <= 0 || a1 + sqrt(x) < 2 * n0 * (c - a2) + EPS;
	} else if (c - a2 == 0) {
		yes = n0 * a1 <= min(-a0, 0);
	}
	cout << yes << "\n";
	return 0;
}
