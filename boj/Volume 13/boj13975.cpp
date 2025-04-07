#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T{};
	cin >> T;
	while (T--) {
		int N{};
		cin >> N;
		priority_queue<ll, vector<ll>, greater<ll>> pq;
		while (N--) {
			ll x{};
			cin >> x;
			pq.push(x);
		}
		ll ans{};
		while (pq.size() > 1) {
			ll x = pq.top(); pq.pop();
			ll y = pq.top(); pq.pop();
			ans += x + y;
			pq.push(x + y);
		}
		cout << ans << "\n";
	}
	return 0;
}
