#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int solve(ll n, ll x, ll y) {
	if (n == 1) {
		return 1;
	}
	return (x < n / 2 || y < n / 2 ? 1 : -1) * solve(n / 2, x % (n / 2), y % (n / 2));
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T{};
	cin >> T;
	while (T--) {
		ll n{}, x{}, y{}, w{}, h{};
		cin >> n >> x >> y >> w >> h;
		for (int i = 0; i < h; ++i) {
			for (int j = 0; j < w; ++j) {
				cout << solve(n, x + j, y + i) << (j == w - 1 ? "\n" : " ");
			}
		}
		cout << "\n";
	}
	return 0;
}
