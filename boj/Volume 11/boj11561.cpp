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
		ll lo = 1, hi = 1e9;
		while (lo + 1 < hi) {
			ll mid = (lo + hi) / 2;
			if (mid * (mid + 1) / 2 > N) {
				hi = mid;
			} else {
				lo = mid;
			}
		}
		cout << lo << "\n";
	}
	return 0;
}
