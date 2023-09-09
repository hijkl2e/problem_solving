#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T{};
	cin >> T;
	while (T--) {
		ll a{}, b{};
		cin >> a >> b;
		ll ans = (a * a) / (b * b);
		cout << ans << "\n";
	}
	return 0;
}
