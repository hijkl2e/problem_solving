#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T{};
	cin >> T;
	while (T--) {
		ll N{};
		cin >> N;
		ll ans{};
		for (int i = 38; i >= 0; --i) {
			ans = 3 * ans + ((N >> i) & 1);
		}
		cout << ans << "\n";
	}
	return 0;
}
