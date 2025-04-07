#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int G{}, S{}, C{};
	cin >> G >> S >> C;
	int power = 3 * G + 2 * S + C;
	if (power < 2) {
		cout << "Copper\n";
	} else {
		cout << (power >= 8 ? "Province" : power >= 5 ? "Duchy" : "Estate") << " or ";
		cout << (power >= 6 ? "Gold" : power >= 3 ? "Silver" : "Copper") << "\n";
	}
	return 0;
}
