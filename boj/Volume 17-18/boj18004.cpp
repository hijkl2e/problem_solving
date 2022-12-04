#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int a{}, b{};
	cin >> a >> b;
	int cnt{};
	while (a > b) {
		if (a % 2) {
			++a;
			++cnt;
		}
		a /= 2;
		++cnt;
	}
	int ans = cnt + b - a;
	while (a > 1) {
		if (a % 2) {
			++a;
			++cnt;
		}
		a /= 2;
		++cnt;
		ans = min(ans, cnt + b - a);
	}
	cout << ans << "\n";
	return 0;
}
