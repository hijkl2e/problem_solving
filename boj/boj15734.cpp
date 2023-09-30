#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int l{}, r{}, a{};
	cin >> l >> r >> a;
	int x = min(max(l, r) - min(l, r), a);
	int ans = 2 * (min(l, r) + x + (a - x) / 2);
	cout << ans << "\n";
	return 0;
}
