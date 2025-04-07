#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	ll a{}, b{};
	cin >> a >> b;
	if (a > b) {
		swap(a, b);
	}
	if (b - a < 2) {
		cout << "0\n\n";
		return 0;
	}
	cout << b - a - 1 << "\n";
	for (ll i = a + 1; i < b; ++i) {
		cout << i << (i == b - 1 ? "\n" : " ");
	}
	return 0;
}
