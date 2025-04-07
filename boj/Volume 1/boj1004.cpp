#include <bits/stdc++.h>

using namespace std;

bool solve(int x1, int y1, int x2, int y2, int d) {
	return (x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1) < d * d;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T{};
	cin >> T;
	while (T--) {
		int x1{}, y1{}, x2{}, y2{}, N{};
		cin >> x1 >> y1 >> x2 >> y2 >> N;
		int ans{};
		while (N--) {
			int cx{}, cy{}, r{};
			cin >> cx >> cy >> r;
			if (solve(x1, y1, cx, cy, r) ^ solve(x2, y2, cx, cy, r)) {
				++ans;
			}
		}
		cout << ans << "\n";
	}
	return 0;
}
