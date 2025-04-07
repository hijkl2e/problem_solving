#include <bits/stdc++.h>

using namespace std;

using ll = long long;

ll solve(ll x) {
	ll ret{}, y{};
	for (ll i = 1; x; i *= 10) {
		int m = x % 10;
		x /= 10;
		ret += 45 * i * x + m * (m - 1) / 2 * i + y * m;
		y += i * m;
	}
	return ret;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, M{};
	cin >> N >> M;
	ll ans = solve(M + 1) - solve(N);
	cout << ans << "\n";
	return 0;
}
