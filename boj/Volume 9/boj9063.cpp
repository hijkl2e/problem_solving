#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9 + 7;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	int minx = INF, maxx = -INF;
	int miny = INF, maxy = -INF;
	while (N--) {
		int x{}, y{};
		cin >> x >> y;
		minx = min(minx, x);
		maxx = max(maxx, x);
		miny = min(miny, y);
		maxy = max(maxy, y);
	}
	int ans = (maxx - minx) * (maxy - miny);
	cout << ans << "\n";
	return 0;
}
