#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int solve(ll X) {
	X = 8 * X - 3;
	ll lo = 2, hi = 3e9;
	while (lo + 1 < hi) {
		ll mid = (lo + hi) / 2;
		if (mid * mid > X) {
			hi = mid;
		} else {
			lo = mid;
		}
	}
	return (lo + 1) / 2;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	ll X{};
	cin >> X;
	ll Y = solve(X);
	X -= Y * (Y - 1) / 2;
	if (Y % 2) {
		X = Y - X + 1;
	}
	cout << X << "/" << (Y - X + 1) << "\n";
	return 0;
}
