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
		vector<int> A(N);
		for (int i = 0; i < N; ++i) {
			cin >> A[i];
		}
		priority_queue<ll, vector<ll>, greater<ll>> pq;
		for (int i = 0; i < N; ++i) {
			pq.push(A[i]);
		}
		ll ans{};
		while (pq.size() > 1) {
			ll x = pq.top(); pq.pop();
			ll y = pq.top(); pq.pop();
			pq.push(x + y);
			ans += x + y;
		}
		cout << ans << "\n";
	}
	return 0;
}
