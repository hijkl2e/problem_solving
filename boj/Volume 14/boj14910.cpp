#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int x{}, y{};
	cin >> x;
	bool yes = true;
	while (cin >> y) {
		if (x > y) {
			yes = false;
			break;
		}
		x = y;
	}
	cout << (yes ? "Good" : "Bad") << "\n";
	return 0;
}
