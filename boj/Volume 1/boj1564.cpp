#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const int MOD = 1e5;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	ll ans = 1;
	int t{};
	for (int i = 1; i <= N; ++i) {
		int j = i;
		while (j % 2 == 0) {
			++t;
			j /= 2;
		}
		while (j % 5 == 0) {
			--t;
			j /= 5;
		}
		ans = j * ans % MOD;
	}
	while (t--) {
		ans = 2 * ans % MOD;
	}
	cout << setfill('0') << setw(5) << ans << "\n";
	return 0;
}
