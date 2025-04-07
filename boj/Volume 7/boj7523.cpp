#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T{};
	cin >> T;
	for (int tc = 1; tc <= T; ++tc) {
		ll N{}, M{};
		cin >> N >> M;
		M -= N;
		ll ans = (M + 2 * N) * (M + 1) / 2;
		if (tc > 1) {
			cout << "\n";
		}
		cout << "Scenario #" << tc << ":\n";
		cout << ans << "\n";
	}
	return 0;
}
