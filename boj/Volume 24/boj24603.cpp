#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, x{}, y{};
	cin >> N >> x >> y;
	int g = gcd(x, y);
	x /= g;
	y /= g;
	while (N--) {
		int a{};
		cin >> a;
		a = a / x * y;
		cout << a << "\n";
	}
	return 0;
}
