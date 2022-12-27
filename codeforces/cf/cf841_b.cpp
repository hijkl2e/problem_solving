#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const ll MOD = 1e9 + 7;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T{};
	cin >> T;
	while (T--) {
		ll N{};
		cin >> N;
		ll ans = (1348 * N - 337) % MOD * N % MOD * (N + 1) % MOD;
		cout << ans << "\n";
	}
	return 0;
}
