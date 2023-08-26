#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int cnt{};
	for (int i = 0; i < 6; ++i) {
		char c{};
		cin >> c;
		if (c == 'W') {
			++cnt;
		}
	}
	int ans = cnt ? (8 - cnt) / 2 : -1;
	cout << ans << "\n";
	return 0;
}
