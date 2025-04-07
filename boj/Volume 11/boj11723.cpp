#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int M{}, y{};
	cin >> M;
	while (M--) {
		string cmd;
		int x{};
		cin >> cmd;
		if (cmd == "all") {
			y = (1 << 21) - 1;
			continue;
		} else if (cmd == "empty") {
			y = 0;
			continue;
		}
		cin >> x;
		if (cmd == "add") {
			y |= 1 << x;
		} else if (cmd == "remove") {
			y &= ~(1 << x);
		} else if (cmd == "check") {
			cout << ((y >> x) & 1) << "\n";
		} else {
			y ^= 1 << x;
		}
	}
	return 0;
}
