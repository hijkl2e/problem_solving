#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T{};
	cin >> T;
	while (T--) {
		ll R{}, C{};
		cin >> R >> C;
		if (R > C) {
			swap(R, C);
		}
		ll ans_w = R * (R + 1) * (2 * R + 1) / 3 + R * R * (C - R - 1);
		ll ans_d = ans_w - R;
		cout << ans_w << " " << ans_d << "\n";
	}
	return 0;
}
