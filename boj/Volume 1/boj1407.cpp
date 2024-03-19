#include <bits/stdc++.h>

using namespace std;

using ll = long long;

ll solve(ll x) {
	ll ret = x;
	for (ll i = 2; i <= x; i *= 2) {
		ret += x / i * i / 2;
	}
	return ret;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	ll N{}, M{};
	cin >> N >> M;
	ll ans = solve(M) - solve(N - 1);
	cout << ans << "\n";
	return 0;
}
