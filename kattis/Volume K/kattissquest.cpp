#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ii = pair<int, int>;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	multiset<ii> S;
	while (N--) {
		string cmd;
		int x{}, y{};
		cin >> cmd >> x;
		if (cmd == "add") {
			cin >> y;
			S.insert({x, y});
			continue;
		}
		ll ans{};
		while (true) {
			auto it = S.upper_bound({x, 1e9});
			if (it == S.begin()) {
				break;
			}
			--it;
			x -= it->first;
			ans += it->second;
			S.erase(it);
		}
		cout << ans << "\n";
	}
	return 0;
}
