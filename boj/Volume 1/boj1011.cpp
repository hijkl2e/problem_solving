#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T{};
	cin >> T;
	while (T--) {
		int x{}, y{};
		cin >> x >> y;
		ll sum{}, ans{};
		while (sum < y - x) {
			sum += ans++ / 2 + 1;
		}
		cout << ans << "\n";
	}
	return 0;
}
