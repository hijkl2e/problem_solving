#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	ll N{}, K{};
	cin >> N >> K;
	K = 1LL << K;
	ll ans{};
	for (ll i = 2; i / 2 <= N; i *= 2) {
		ll x = i - (i > K ? i / K : 1);
		ans += max(min(i, N + 1) - x, 0LL);
	}
	cout << ans << "\n";
	return 0;
}
