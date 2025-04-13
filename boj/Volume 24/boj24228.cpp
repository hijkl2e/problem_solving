#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	ll N{}, R{};
	cin >> N >> R;
	ll ans = 2 * R + N - 1;
	cout << ans << "\n";
	return 0;
}
