#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const ll MOD = 998244353;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int R{}, C{};
	cin >> R >> C;
	ll ans = 1;
	for (int i = R + 1; i <= R * C; ++i) {
		ans = ans * i % MOD;
	}
	cout << ans << "\n";
	return 0;
}
