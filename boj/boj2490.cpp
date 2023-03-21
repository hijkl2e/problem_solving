#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	for (int i = 0; i < 3; ++i) {
		int X{};
		for (int j = 0; j < 4; ++j) {
			int x{};
			cin >> x;
			X += x;
		}
		char c = X == 4 ? 'E' : ('D' - X);
		cout << c << "\n";
	}
	return 0;
}
