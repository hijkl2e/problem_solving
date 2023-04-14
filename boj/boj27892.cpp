#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	ll x{}, N{};
	cin >> x >> N;
	while ((x > 8 || x % 4) && N--) {
		if (x % 2) {
			x = (2 * x) ^ 6;
		} else {
			x = (x / 2) ^ 6;
		}
	}
	if (N > 0) {
		if (x == 0) {
			int r = N % 4;
			x = r == 1 ? 6 : r == 2 ? 5 : r == 3 ? 12 : 0;
		} else if (x == 8) {
			int r = N % 3;
			x = r == 1 ? 2 : r == 2 ? 7 : 8;
		}
	}
	cout << x << "\n";
	return 0;
}
