#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	ll R{}, C{}, N{};
	cin >> R >> C >> N;
	ll ans = ((R - 1) / N + 1) * ((C - 1) / N + 1);
	cout << ans << "\n";
	return 0;
}
