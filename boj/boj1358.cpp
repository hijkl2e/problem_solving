#include <bits/stdc++.h>

using namespace std;

int dist(int x1, int y1, int x2, int y2) {
	return (x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int w{}, h{}, X{}, Y{}, P{};
	cin >> w >> h >> X >> Y >> P;
	int R = h / 2;
	int ans{};
	while (P--) {
		int x{}, y{};
		cin >> x >> y;
		if ((X <= x && x <= X + w && Y <= y && y <= Y + h)
				|| min(dist(X, Y + R, x, y), dist(X + w, Y + R, x, y)) <= R * R) {
			++ans;
		}
	}
	cout << ans << "\n";
	return 0;
}
