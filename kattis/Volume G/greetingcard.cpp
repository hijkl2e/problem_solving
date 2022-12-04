#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const int dx[12]{0, 0, 2018, -2018, 1118, 1118, 1680, 1680, -1118, -1118, -1680, -1680};
const int dy[12]{2018, -2018, 0, 0, 1680, -1680, 1118, -1118, 1680, -1680, 1118, -1118};
const ll INF = 3210987654LL;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	unordered_set<ll> S;
	int ans{};
	while (N--) {
		ll x{}, y{};
		cin >> x >> y;
		x += 2018;
		y += 2018;
		for (int i = 0; i < 12; ++i) {
			ll nx = x + dx[i];
			ll ny = y + dy[i];
			if (S.count(nx * INF + ny)) {
				++ans;
			}
		}
		S.insert(x * INF + y);
	}
	cout << ans << "\n";
	return 0;
}
