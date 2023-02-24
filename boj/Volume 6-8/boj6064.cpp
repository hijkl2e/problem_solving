#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T{};
	cin >> T;
	while (T--) {
		int M{}, N{}, x{}, y{};
		cin >> M >> N >> x >> y;
		int ans = -1;
		for (int i = 0;; ++i) {
			int z = i * M + x - 1;
			if (z % N == y - 1) {
				ans = z + 1;
				break;
			} else if (i && (z - x + 1) % N == 0) {
				break;
			}
		}
		cout << ans << "\n";
	}
	return 0;
}
