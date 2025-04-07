#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T{};
	cin >> T;
	for (int tc = 1; tc <= T; ++tc) {
		int x{}, y{}, z{};
		char c{}, d{};
		cin >> x >> c >> y >> d >> z;
		if (c == '-') {
			y *= -1;
		}
		cout << "Case " << tc << ": " << (x + y == z ? "YES" : "NO") << "\n";
	}
	return 0;
}
