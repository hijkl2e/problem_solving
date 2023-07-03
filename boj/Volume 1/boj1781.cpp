#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	vector<vector<ll>> A(N + 1);
	for (int i = 0; i < N; ++i) {
		ll x{}, y{};
		cin >> x >> y;
		A[x].push_back(y);
	}
	priority_queue<ll> pq;
	ll ans{};
	for (int i = N; i > 0; --i) {
		for (ll x : A[i]) {
			pq.push(x);
		}
		if (pq.size()) {
			ans += pq.top();
			pq.pop();
		}
	}
	cout << ans << "\n";
	return 0;
}
