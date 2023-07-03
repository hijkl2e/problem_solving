#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int a{}, b{}, c{};
	while (cin >> a >> b >> c, a || b || c) {
		if (a + c == 2 * b) {
			cout << "AP " << c + b - a << "\n";
		} else {
			cout << "GP " << c * b / a << "\n";
		}
	}
	return 0;
}
