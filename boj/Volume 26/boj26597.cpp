#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int Q{};
	cin >> Q;
	ll lo = -1e18, hi = 1e18;
	int ans = -1;
	for (int i = 1; i <= Q; ++i) {
		ll x{};
		char c{};
		cin >> x >> c;
		if (c == '^') {
			lo = max(lo, x + 1);
		} else {
			hi = min(hi, x - 1);
		}
		if (lo > hi) {
			ans = i;
			break;
		} else if (lo == hi && ans == -1) {
			ans = i;
		}
	}
	if (ans == -1) {
		cout << "Hmm...\n";
	} else {
		cout << (lo == hi ? "I got it!" : "Paradox!") << "\n";
		cout << ans << "\n";
	}
	return 0;
}
