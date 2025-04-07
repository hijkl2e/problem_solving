#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, M{};
	cin >> N >> M;
	N += M;
	ll ans{};
	while (N--) {
		int x{};
		cin >> x;
		ans += x;
	}
	cout << ans << "\n";
	return 0;
}
