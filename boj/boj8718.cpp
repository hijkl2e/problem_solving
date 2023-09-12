#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int x{}, k{};
	cin >> x >> k;
	x *= 1000;
	k *= 7000;
	int ans{};
	for (int i = 1; i < 8; i *= 2) {
		if (x >= k / i) {
			ans = k / i;
			break;
		}
	}
	cout << ans << "\n";
	return 0;
}
