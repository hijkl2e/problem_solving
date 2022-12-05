#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int a{}, b{}, c{};
	while (cin >> a >> b >> c) {
		cout << "0.";
		a *= 10;
		while (c--) {
			cout << a / b;
			a = a % b * 10;
		}
		cout << "\n";
	}
	return 0;
}
