#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int k{}, w{}, m{};
	cin >> k >> w >> m;
	int ans = k < w ? (w - k - 1) / m + 1 : 0;
	cout << ans << "\n";
	return 0;
}
