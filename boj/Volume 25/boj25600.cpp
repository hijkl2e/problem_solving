#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	int ans{};
	while (N--) {
		int a{}, d{}, g{};
		cin >> a >> d >> g;
		int x = a * (d + g);
		if (a == d + g) {
			x *= 2;
		}
		ans = max(ans, x);
	}
	cout << ans << "\n";
	return 0;
}
