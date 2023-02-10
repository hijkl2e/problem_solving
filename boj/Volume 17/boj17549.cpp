#include <bits/stdc++.h>

using namespace std;

bool solve(int x1, int y1, int x2, int y2) {
	return x1 == x2 || abs(x2 - x1) == abs(y2 - y1);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int x1{}, y1{}, x2{}, y2{};
	char c{};
	cin >> c >> y1;
	x1 = c - 'a';
	y1 = 2 * (y1 - 1) + abs(x1 - 5);
	cin >> c >> y2;
	x2 = c - 'a';
	y2 = 2 * (y2 - 1) + abs(x2 - 5);
	int ans{};
	for (int i = 0; i < 11; ++i) {
		int lo = abs(i - 5);
		int hi = 21 - lo;
		for (int j = lo; j < hi; j += 2) {
			if ((x1 == i && y1 == j) || (x2 == i && y2 == j)) {
				continue;
			}
			if (solve(x1, y1, i, j) && solve(i, j, x2, y2)) {
				++ans;
			}
		}
	}
	cout << ans << "\n";
	return 0;
}
