#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	ll N{}, K{}, R{}, Q{};
	cin >> N >> K >> R >> Q;
	vector<ll> x(N + 2);
	vector<ll> y(N + 2);
	int prev{};
	while (K--) {
		int k{};
		cin >> k;
		cin >> x[k] >> y[k];
		if (k > 1) {
			for (int i = prev + 1; i < k; ++i) {
				x[i] = x[prev] + (x[k] - x[prev]) / (k - prev) * (i - prev);
				y[i] = y[prev] + (y[k] - y[prev]) / (k - prev) * (i - prev);
			}
		}
		prev = k;
	}
	x[N + 1] = 2 * x[N] - x[N - 1];
	y[N + 1] = 2 * y[N] - y[N - 1];
	vector<int> dir(N + 1);
	for (int i = 1; i <= N; ++i) {
		int xd = x[i + 1] - x[i];
		int yd = y[i + 1] - y[i];
		dir[i] = xd == 1 ? 0 : xd == -1 ? 1 : yd == 1 ? 2 : 3;
	}
	while (Q--) {
		ll k{}, a{}, b{};
		cin >> k >> a >> b;
		ll dist = (x[k] - a) * (x[k] - a) + (y[k] - b) * (y[k] - b);
		string ans;
		if (dist > R * R || (dir[k] / 2 ? (x[k] == a) : (y[k] == b))) {
			ans = "gori";
		} else if ((dir[k] % 2) ^ (dir[k] / 2 ? (x[k] > a) : (y[k] < b))) {
			ans = "safe";
		} else {
			ans = "unsafe";
		}
		cout << ans << "\n";
	}
	return 0;
}
