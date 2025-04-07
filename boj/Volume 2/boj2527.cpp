#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T = 4;
	while (T--) {
		int x1{}, y1{}, p1{}, q1{};
		cin >> x1 >> y1 >> p1 >> q1;
		int x2{}, y2{}, p2{}, q2{};
		cin >> x2 >> y2 >> p2 >> q2;
		char ans = 'a';
		if (p1 < x2 || p2 < x1 || q1 < y2 || q2 < y1) {
			ans = 'd';
		} else if ((x1 == p2 || x2 == p1) && (y1 == q2 || y2 == q1)) {
			ans = 'c';
		} else if (x1 == p2 || x2 == p1 || y1 == q2 || y2 == q1) {
			ans = 'b';
		}
		cout << ans << "\n";
	}
	return 0;
}
