#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int h{}, m{};
	cin >> h >> m;
	int ans = 60 * (h - 9) + m;
	cout << ans << "\n";
	return 0;
}
