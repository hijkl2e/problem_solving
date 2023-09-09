#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T{};
	cin >> T;
	while (T--) {
		ll a{}, b{}, c{}, d{};
		cin >> a >> b >> c >> d;
		ll res = a * b - c * d;
		cout << (res > 0 ? "TelecomParisTech" : res < 0 ? "Eurecom" : "Tie") << "\n";
	}
	return 0;
}
