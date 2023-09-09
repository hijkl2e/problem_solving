#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	ll l{}, w{}, h{}, N{};
	cin >> l >> w >> h >> N;
	vector<ll> A(20);
	while (N--) {
		int x{}, y{};
		cin >> x >> y;
		A[x] = y;
	}
	ll cnt{};
	int ans{};
	for (int i = 19; i >= 0; --i) {
		ll x = min((l >> i) * (w >> i) * (h >> i) - (cnt >> (3 * i)), A[i]);
		cnt += x << (3 * i);
		ans += x;
	}
	cout << (cnt == l * w * h ? ans : -1) << "\n";
	return 0;
}
