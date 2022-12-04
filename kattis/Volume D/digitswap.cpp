#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int x{};
	cin >> x;
	int ans = x % 10 * 10 + x / 10;
	cout << ans << "\n";
	return 0;
}
