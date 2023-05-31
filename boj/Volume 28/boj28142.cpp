#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const ll P = 1e9 + 7;

ll pow(ll x, ll y) {
	ll ret = 1;
	while (y) {
		if (y % 2) {
			ret = ret * x % P;
		}
		x = x * x % P;
		y /= 2;
	}
	return ret;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	ll N{};
	cin >> N;
	ll X = N / 255 * 255;
	for (ll i = X + 1; i <= N; ++i) {
		X = abs(X - i);
		if (i % 3 == 0) {
			X = (X % P) * (i % P) % P;
		}
		if (i % 15 == 0) {
			X &= i;
		}
		if (i % 63 == 0) {
			X ^= i;
		}
		if (i % 255 == 0) {
			X |= i;
		}
		if (i % 1023 == 0) {
			X = X % P * pow(2LL, i) % P;
		}
	}
	cout << X << "\n";
	return 0;
}
