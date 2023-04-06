#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T{};
	cin >> T;
	while (T--) {
		int N{};
		cin >> N;
		int ans{}, y{}, z{};
		while (N--) {
			int x{};
			cin >> x;
			if (x == 1) {
				ans = max(ans, (y ? y / 2 + 1 : 0) + ++z);
			} else {
				y += z;
				z = 0;
			}
		}
		cout << ans << "\n";
	}
	return 0;
}
