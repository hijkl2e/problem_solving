#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int L{}, a{}, b{}, c{}, d{};
	cin >> L >> a >> b >> c >> d;
	int ans = L - max((a - 1) / c, (b - 1) / d) - 1;
	cout << ans << "\n";
	return 0;
}
