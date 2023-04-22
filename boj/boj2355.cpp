#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	ll a{}, b{};
	cin >> a >> b;
	if (a > b) {
		swap(a, b);
	}
	__int128 cnt = b - a + 1;
	ll ans = cnt * (cnt + 1) / 2 + (a - 1) * cnt;
	cout << ans << "\n";
	return 0;
}
