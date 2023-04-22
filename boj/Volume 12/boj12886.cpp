#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int a{}, b{}, c{};
	cin >> a >> b >> c;
	int x = (a + b + c) / gcd(gcd(a, b), c);
	cout << (x % 3 == 0 && __builtin_popcount(x / 3) == 1) << "\n";
	return 0;
}
