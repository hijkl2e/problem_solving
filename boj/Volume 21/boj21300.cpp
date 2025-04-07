#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int ans{};
	for (int i = 0; i < 6; ++i) {
		int x{};
		cin >> x;
		ans += x;
	}
	ans *= 5;
	cout << ans << "\n";
	return 0;
}
