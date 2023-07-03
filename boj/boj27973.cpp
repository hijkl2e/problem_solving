#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int Q{};
	cin >> Q;
	ll n = 1, a = 1, b = 0;
	while (Q--) {
		int q{}, x{};
		cin >> q;
		if (q == 3) {
			cout << a * n + b << "\n";
			continue;
		}
		cin >> x;
		if (q == 0) {
			b += x;
		} else if (q == 1) {
			a *= x, b *= x;
		} else {
			n += x;
		}
	}
	return 0;
}
