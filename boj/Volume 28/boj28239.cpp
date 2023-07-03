#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	while (N--) {
		ll x{};
		cin >> x;
		int ans_x{}, ans_y{};
		if (__builtin_popcountll(x) == 1) {
			ans_x = ans_y = __builtin_ctzll(x) - 1;
		} else {
			ans_x = __builtin_ctzll(x);
			x -= x & -x;
			ans_y = __builtin_ctzll(x);
		}
		cout << ans_x << " " << ans_y << "\n";
	}
	return 0;
}
