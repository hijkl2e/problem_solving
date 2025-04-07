#include <bits/stdc++.h>

using namespace std;

using ll = long long;

ll solve(ll x) {
	ll ret = x;
	while (x % 4) {
		ret ^= --x;
	}
	return ret;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	ll ans{};
	while (N--) {
		ll a{}, b{};
		cin >> a >> b;
		ans ^= solve(a + b - 1) ^ solve(a - 1);
	}
	cout << (ans ? "koosaga" : "cubelover") << "\n";
	return 0;
}
