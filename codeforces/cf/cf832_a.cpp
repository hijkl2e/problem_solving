#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T{};
	cin >> T;
	while (T--) {
		int N{};
		cin >> N;
		ll ans{};
		while (N--) {
			int x{};
			cin >> x;
			ans += x;
		}
		ans = abs(ans);
		cout << ans << "\n";
	}
	return 0;
}
