#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int X{}, Y{}, Z{};
	cin >> X >> Y >> Z;
	int x{}, y{}, z{};
	cin >> x >> y >> z;
	char ans = 'E';
	if (y == Y) {
		if (x == X) {
			ans = 'A';
		} else if (x >= (X + 1) / 2) {
			ans = 'B';
		} else {
			ans = 'C';
		}
	} else if (y >= (Y + 1) / 2) {
		ans = 'D';
	}
	cout << ans << "\n";
	return 0;
}
