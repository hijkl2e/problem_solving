#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T{};
	cin >> T;
	while (T--) {
		ll l{}, v1{}, v2{}, t{}, s{}, n = 1;
		cin >> l >> v1 >> v2 >> t >> s;
		int ans = -1;
		for (int k = 0; n > 0; ++k) {
			if (t * n >= v2 - v1) {
				ans = k;
				break;
			}
			ll vf = l / (s * (k + 1));
			ll nf = max((v2 - vf - 1) / t, 0LL);
			n = 2 * (n - nf);
			v2 -= nf * t;
		}
		if (ans == -1) {
			cout << "impossible\n";
		} else {
			cout << ans << "\n";
		}
	}
	return 0;
}
