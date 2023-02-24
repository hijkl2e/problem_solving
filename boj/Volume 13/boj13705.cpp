#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const __float128 PI = 3.1415926535897932384626433832795029q;

__float128 sin(__float128 x) {
	int q = x / (2 * PI);
	x -= q * (2 * PI);
	__float128 ret{}, y = 1;
	for (int i = 1; i < 50; ++i) {
		y *= x / i;
		if (i % 2) {
			ret += (i / 2 % 2 ? -1 : 1) * y;
		}
	}
	return ret;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int A{}, B{}, C{};
	cin >> A >> B >> C;
	__float128 lo = 0, hi = 1e6;
	for (int i = 0; i < 100; ++i) {
		__float128 mid = (lo + hi) / 2;
		if (A * mid + B * sin(mid) > C) {
			hi = mid;
		} else {
			lo = mid;
		}
	}
	ll x = 10000000 * lo;
	x = x / 10 + (x % 10 < 5 ? 0 : 1);
	cout << x / 1000000 << "." << setw(6) << setfill('0') << x % 1000000 << "\n";
	return 0;
}
