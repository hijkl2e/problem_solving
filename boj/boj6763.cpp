#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int x{}, y{};
	cin >> x >> y;
	if (x < y) {
		cout << "You are speeding and your fine is $";
		cout << (y - x > 30 ? 500 : y - x > 20 ? 270 : 100) << ".\n";
	} else {
		cout << "Congratulations, you are within the speed limit!\n";
	}
	return 0;
}
