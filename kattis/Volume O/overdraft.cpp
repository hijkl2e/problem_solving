#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	int bal{};
	int ans{};
	while (N--) {
		int x{};
		cin >> x;
		bal += x;
		ans = min(ans, bal);
	}
	ans = abs(ans);
	cout << ans << "\n";
	return 0;
}
