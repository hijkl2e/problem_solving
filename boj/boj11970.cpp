#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int a{}, b{}, c{}, d{};
	cin >> a >> b >> c >> d;
	int ans{};
	for (int i = 0; i < 100; ++i) {
		if ((a <= i && i < b) || (c <= i && i < d)) {
			++ans;
		}
	}
	cout << ans << "\n";
	return 0;
}
