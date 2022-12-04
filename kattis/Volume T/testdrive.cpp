#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int a{}, b{}, c{};
	cin >> a >> b >> c;
	a = b - a;
	b = c - b;
	if ((a > 0 && b < 0) || (a < 0 && b > 0)) {
		cout << "turned\n";
	} else {
		a = abs(a);
		b = abs(b);
		cout << (a < b ? "accelerated" : a > b ? "braked" : "cruised") << "\n";
	}
	return 0;
}
