#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const ll MOD = 1e9 + 7;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	ll ans = 1;
	for (int i = 1; i <= N; ++i) {
		ans = ans * i % MOD;
	}
	cout << ans << "\n";
	return 0;
}
