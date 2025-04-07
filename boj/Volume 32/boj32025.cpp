#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int h{}, w{};
	cin >> h >> w;
	int ans = 50 * min(h, w);
	cout << ans << "\n";
	return 0;
}
