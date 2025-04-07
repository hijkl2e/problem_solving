#include <bits/stdc++.h>

using namespace std;

const int dx[4]{0, 1, 0, -1};
const int dy[4]{1, 0, -1, 0};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T{};
	cin >> T;
	cin.ignore();
	while (T--) {
		string S;
		getline(cin, S);
		int d{}, x{}, y{}, minx{}, maxx{}, miny{}, maxy{};
		for (char c : S) {
			if (c == 'F') {
				x += dx[d];
				y += dy[d];
			} else if (c == 'B') {
				x -= dx[d];
				y -= dy[d];
			} else if (c == 'L') {
				d = (d + 3) % 4;
			} else {
				d = (d + 1) % 4;
			}
			minx = min(minx, x);
			maxx = max(maxx, x);
			miny = min(miny, y);
			maxy = max(maxy, y);
		}
		int ans = (maxx - minx) * (maxy - miny);
		cout << ans << "\n";
	}
	return 0;
}
