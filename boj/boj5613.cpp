#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int x{}, y{};
	cin >> x;
	char op{};
	while (cin >> op >> y) {
		if (op == '+') {
			x += y;
		} else if (op == '-') {
			x -= y;
		} else if (op == '*') {
			x *= y;
		} else {
			x /= y;
		}
	}
	cout << x << "\n";
	return 0;
}
