#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	ll x{};
	cin >> N >> x;
	ll ans{};
	if (N == 1 || N == 5) {
		ans = 8 * x + N - 1;
	} else if (x % 2) {
		ans = 4 * x - N + 5;
	} else {
		ans = 4 * x + N - 1;
	}
	cout << ans << "\n";
	return 0;
}
