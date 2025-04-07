#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int H{}, P{};
	cin >> H >> P;
	int ans{};
	for (int i = H;; i += H) {
		if (((i - 1) / 1000 + 1) * 500000 + 60 * i * P > 6000000 + 11 * i * P) {
			ans = i / H;
			break;
		}
	}
	cout << ans << "\n";
	return 0;
}
