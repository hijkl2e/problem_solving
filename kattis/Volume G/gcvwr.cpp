#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int G{}, T{}, N{};
	cin >> G >> T >> N;
	int ans = (G - T) / 10 * 9;
	while (N--) {
		int x{};
		cin >> x;
		ans -= x;
	}
	cout << ans << "\n";
	return 0;
}
