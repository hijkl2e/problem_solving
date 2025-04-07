#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	ll S{};
	cin >> S;
	int ans{};
	for (ll i = 1;; ++i) {
		if (S < i * (i + 1) / 2) {
			ans = i - 1;
			break;
		}
	}
	cout << ans << "\n";
	return 0;
}
