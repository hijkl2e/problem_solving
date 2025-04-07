#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, x{};
	cin >> N >> x;
	int ans = x;
	while (N--) {
		int a{}, b{};
		cin >> a >> b;
		x += a - b;
		if (x < 0) {
			ans = 0;
			break;
		}
		ans = max(ans, x);
	}
	cout << ans << "\n";
	return 0;
}
