#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	ll N{};
	cin >> N;
	ll ans{};
	for (ll i = max(N - 200, 1LL); i < N; ++i) {
		ll j = i;
		ll sum = i;
		while (j) {
			sum += j % 10;
			j /= 10;
		}
		if (sum == N) {
			ans = i;
			break;
		}
	}
	cout << ans << "\n";
	return 0;
}
