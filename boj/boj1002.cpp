#include <bits/stdc++.h>

using namespace std;

int square(int x) {
	return x * x;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T{};
	cin >> T;
	while (T--) {
		int x1{}, y1{}, r1{}, x2{}, y2{}, r2{};
		cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
		int d = square(x2 - x1) + square(y2 - y1);
		int ans{};
		if (d) {
			if (d == square(r1 - r2) || d == square(r1 + r2)) {
				ans = 1;
			} else if (square(r1 - r2) < d && d < square(r1 + r2)) {
				ans = 2;
			}
		} else if (r1 == r2) {
			ans = -1;
		}
		cout << ans << "\n";
	}
	return 0;
}
