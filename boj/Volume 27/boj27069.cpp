#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T{};
	cin >> T;
	while (T--) {
		ll a{}, b{}, c{}, n{}, k{};
		cin >> a >> b >> c >> n >> k;
		if (a < c) {
			swap(a, c);
		}
		ll maxv = max(a, b) * (n - k) + max(b * (k - 1),
				(k - 1) / 2 * (a + c) + ((k - 1) % 2) * max(b, c));
		ll minv = min(b, c) * (k - 1) + min(b * (n - k),
				(n - k) / 2 * (a + c) + ((n - k) % 2) * min(a, b));
		cout << maxv << " " << minv << "\n";
	}
	return 0;
}
