#include <bits/stdc++.h>

using namespace std;

using ll = long long;

ll pow(ll x, ll y, ll mod) {
	ll ret = 1;
	while (y) {
		if (y % 2) {
			ret = ret * x % mod;
		}
		x = x * x % mod;
		y /= 2;
	}
	return ret;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	ll A{}, B{}, C{};
	cin >> A >> B >> C;
	cout << pow(A, B, C) << "\n";
	return 0;
}
