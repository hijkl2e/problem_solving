#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T{};
	cin >> T;
	while (T--) {
		ll N{};
		cin >> N;
		ll M = N * (N + 1) / 2;
		ll lo = 1, hi = N + 1;
		while (lo + 1 < hi) {
			ll mid = (lo + hi) / 2;
			ll cnt = mid * (mid - 1);
			if (M < cnt) {
				hi = mid;
			} else {
				lo = mid;
			}
		}
		cout << lo << "\n";
	}
	return 0;
}
