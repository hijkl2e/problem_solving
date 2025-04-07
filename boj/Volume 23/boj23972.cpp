#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	ll K{}, N{};
	cin >> K >> N;
	ll ans{};
	if (N > 1) {
		ans = (N * K - 1) / (N - 1) + 1;
	} else {
		ans = -1;
	}
	cout << ans << "\n";
	return 0;
}
