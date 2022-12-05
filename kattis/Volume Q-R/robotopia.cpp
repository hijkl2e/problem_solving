#include <bits/stdc++.h>

using namespace std;

using ii = pair<int, int>;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T{};
	cin >> T;
	while (T--) {
		int l1{}, a1{}, l2{}, a2{}, lt{}, at{};
		cin >> l1 >> a1 >> l2 >> a2 >> lt >> at;
		ii ans{-1, -1};
		for (int i = 1; l1 * i + l2 <= lt && a1 * i + a2 <= at; ++i) {
			if ((lt - l1 * i) % l2 == 0 && (at - a1 * i) % a2 == 0
					&& (lt - l1 * i) / l2 == (at - a1 * i) / a2) {
				if (ans.first == -1) {
					ans = {i, (lt - l1 * i) / l2};
				} else {
					ans.second = -1;
				}
			}
		}
		if (ans.second == -1) {
			cout << "?\n";
		} else {
			cout << ans.first << " " << ans.second << "\n";
		}
	}
	return 0;
}
