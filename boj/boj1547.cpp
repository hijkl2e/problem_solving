#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int M{};
	cin >> M;
	int ans = 1;
	while (M--) {
		int x{}, y{};
		cin >> x >> y;
		ans = ans == x ? y : ans == y ? x : ans;
	}
	cout << ans << "\n";
	return 0;
}
