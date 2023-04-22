#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	int ans{}, cnt{};
	while (N--) {
		int x{};
		cin >> x;
		if (x) {
			ans += ++cnt;
		} else {
			cnt = 0;
		}
	}
	cout << ans << "\n";
	return 0;
}
