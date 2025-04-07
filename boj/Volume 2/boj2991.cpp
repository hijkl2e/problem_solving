#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int a{}, b{}, c{}, d{};
	cin >> a >> b >> c >> d;
	for (int i = 0; i < 3; ++i) {
		int x{};
		cin >> x;
		int ans = ((x - 1) % (a + b) < a) + ((x - 1) % (c + d) < c);
		cout << ans << "\n";
	}
	return 0;
}
