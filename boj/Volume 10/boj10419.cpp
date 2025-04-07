#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T{};
	cin >> T;
	while (T--) {
		int x{};
		cin >> x;
		int ans{};
		for (int i = 1;; ++i) {
			if (i * i + i > x) {
				ans = i - 1;
				break;
			}
		}
		cout << ans << "\n";
	}
	return 0;
}
