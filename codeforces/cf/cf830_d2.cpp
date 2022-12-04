#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	set<ll> S;
	S.insert(0);
	map<ll, ll> mex;
	map<ll, set<ll>> used;
	map<ll, set<ll>> del;
	int Q{};
	cin >> Q;
	while (Q--) {
		char q{};
		ll x{};
		cin >> q >> x;
		if (q == '+') {
			S.insert(x);
			for (ll K : used[x]) {
				del[K].erase(x);
			}
		} else if (q == '-') {
			S.erase(x);
			for (ll K : used[x]) {
				del[K].insert(x);
			}
		} else {
			ll K = x;
			if (del[K].size()) {
				cout << *del[K].begin() << "\n";
				continue;
			}
			ll &ans = mex[K];
			while (S.count(ans)) {
				used[ans].insert(K);
				ans += K;
			}
			cout << ans << "\n";
		}
	}
	return 0;
}
