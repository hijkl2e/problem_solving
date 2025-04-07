#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9 + 7;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, M{};
	cin >> N >> M;
	int x{}, y{};
	x = y = INF;
	while (M--) {
		int u{}, v{};
		cin >> u >> v;
		x = min(x, u);
		y = min(y, v);
	}
	x = min(x, 6 * y);
	int ans = N / 6 * x + min(x, N % 6 * y);
	cout << ans << "\n";
	return 0;
}
