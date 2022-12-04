#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T{};
	cin >> T;
	while (T--) {
		ll P{}, R{}, F{};
		cin >> P >> R >> F;
		for (int i = 0;; ++i) {
			if (P > F) {
				cout << i << "\n";
				break;
			}
			P *= R;
		}
	}
	return 0;
}
