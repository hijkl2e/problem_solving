#include <bits/stdc++.h>

using namespace std;

using ll = long long;

pair<ll, ll> ext_gcd(ll a, ll b) {
	if (b) {
		auto [x, y] = ext_gcd(b, a % b);
		return {y, x - (a / b) * y};
	} else {
		return {1, 0};
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	ll A{}, B{}, C{}, x1{}, x2{}, y1{}, y2{};
	cin >> A >> B >> C >> x1 >> x2 >> y1 >> y2;
	if ((A < 0) ^ (C > 0)) {
		swap(x1, x2);
		x1 *= -1, x2 *= -1;
	}
	if ((B < 0) ^ (C > 0)) {
		swap(y1, y2);
		y1 *= -1, y2 *= -1;
	}
	if (A == 0) {
		swap(A, B);
		swap(x1, y1);
		swap(x2, y2);
	}
	A = abs(A), B = abs(B), C = abs(C);
	ll g = gcd(A, B);
	ll ans{};
	if (x1 > x2 || y1 > y2 || (g && C % g)) {
		ans = 0;
	} else if (g == 0) {
		ans = C ? 0 : ((x2 - x1 + 1) * (y2 - y1 + 1));
	} else if (B == 0) {
		ans = C % A == 0 && x1 <= C / A && C / A <= x2 ? y2 - y1 + 1 : 0;
	} else {
		auto [x0, y0] = ext_gcd(A, B);
		x0 *= C / g;
		y0 *= C / g;
		ll lo = (g * (x1 - x0) + (x1 > x0 ? B - 1 : 0)) / B;
		ll hi = (g * (x2 - x0) - (x2 < x0 ? B - 1 : 0)) / B;
		lo = max(lo, (g * (y0 - y2) + (y0 > y2 ? A - 1 : 0)) / A);
		hi = min(hi, (g * (y0 - y1) - (y0 < y1 ? A - 1 : 0)) / A);
		ans = max(hi - lo + 1, 0LL);
	}
	cout << ans << "\n";
	return 0;
}
