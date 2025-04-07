#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const ll MOD = 1e9 + 7;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T{};
	cin >> T;
	while (T--) {
		int N{};
		cin >> N;
		vector<ll> A(N);
		for (int i = 0; i < N; ++i) {
			cin >> A[i];
		}
		priority_queue<ll, vector<ll>, greater<ll>> pq;
		for (int i = 0; i < N; ++i) {
			pq.push(A[i]);
		}
		ll ans = 1;
		while (pq.size() > 1) {
			ll x = pq.top(); pq.pop();
			ll y = pq.top(); pq.pop();
			ans = ans * ((x % MOD) * (y % MOD) % MOD) % MOD;
			pq.push(x * y);
		}
		cout << ans << "\n";
	}
	return 0;
}
