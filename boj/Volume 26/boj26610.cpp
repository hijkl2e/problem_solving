#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int Q{};
	cin >> Q;
	while (Q--) {
		ll X{}, T{}, N{};
		cin >> X >> T >> N;
		ll lo = 1, hi = 2e8 + 1;
		while (lo + 1 < hi) {
			ll mid = (lo + hi) / 2;
			ll q = mid / T;
			ll r = mid % T;
			ll res = X * mid + q * (q + 1) / 2 * T + (q + 1) * r;
			if (N < res) {
				hi = mid;
			} else {
				lo = mid;
			}
		}
		ll Y = lo;
		N -= X * Y;
		lo = (Y - 1) / T;
		hi = Y;
		while (lo + 1 < hi) {
			ll mid = (lo + hi) / 2;
			ll q = mid - (Y - mid) / (T - 1);
			ll r = (Y - mid) % (T - 1);
			ll res = mid * (mid + 1) / 2 * T - q * (q + 1) / 2 * (T - 1) + q * r;
			if (res < N) {
				lo = mid;
			} else {
				hi = mid;
			}
		}
		cout << hi << "\n";
	}
	return 0;
}
