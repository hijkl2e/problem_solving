#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	set<ll> S;
	S.insert(0);
	map<ll, ll> mex;
	int Q{};
	cin >> Q;
	while (Q--) {
		char q{};
		ll x{};
		cin >> q >> x;
		if (q == '+') {
			S.insert(x);
		} else {
			ll K = x;
			ll &ans = mex[K];
			while (S.count(ans)) {
				ans += K;
			}
			cout << ans << "\n";
		}
	}
	return 0;
}
