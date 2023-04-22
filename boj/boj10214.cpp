#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T{};
	cin >> T;
	while (T--) {
		int X{}, Y{};
		for (int i = 0; i < 9; ++i) {
			int x{}, y{};
			cin >> x >> y;
			X += x, Y += y;
		}
		cout << (X > Y ? "Yonsei" : X < Y ? "Korea" : "Draw") << "\n";
	}
	return 0;
}
