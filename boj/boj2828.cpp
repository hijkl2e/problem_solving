#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, M{}, K{};
	cin >> N >> M >> K;
	int x = 1, ans{};
	while (K--) {
		int y{};
		cin >> y;
		if (y < x) {
			ans += x - y;
			x = y;
		} else if (y >= x + M) {
			ans += y - x - M + 1;
			x = y - M + 1;
		}
	}
	cout << ans << "\n";
	return 0;
}
