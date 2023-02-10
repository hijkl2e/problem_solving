#include <bits/stdc++.h>

using namespace std;

const double EPS = 1e-9;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int a2{}, a1{}, a0{}, c{}, n0{};
	cin >> a2 >> a1 >> a0 >> c >> n0;
	bool yes{};
	if (a2 - c > 0) {
		int x = a1 * a1 - 4 * (a2 - c) * a0;
		yes = x <= 0 || -a1 + sqrt(x) < 2 * n0 * (a2 - c) + EPS;
	} else if (a2 - c == 0) {
		yes = n0 * a1 >= max(-a0, 0);
	}
	cout << yes << "\n";
	return 0;
}
