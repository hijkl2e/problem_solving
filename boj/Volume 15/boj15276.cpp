#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	set<int> S;
	for (int i = 100; i < 1000; ++i) {
		int x = i;
		x = x * 10 + i % 10;
		x = x * 10 + i / 10 % 10;
		x = x * 10 + i / 100;
		S.insert(x);
	}
	int T{};
	cin >> T;
	while (T--) {
		int x{};
		cin >> x;
		auto it = S.lower_bound(x);
		int ans = *it;
		if (it != S.begin()) {
			--it;
			if (ans - x >= x - *it) {
				ans = *it;
			}
		}
		cout << ans << "\n";
	}
	return 0;
}
