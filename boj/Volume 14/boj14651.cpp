#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const ll MOD = 1e9 + 9;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	if (N == 1) {
		cout << "0\n";
		return 0;
	}
	ll ans = 2;
	for (int i = 0; i < N - 2; ++i) {
		ans = 3 * ans % MOD;
	}
	cout << ans << "\n";
	return 0;
}
