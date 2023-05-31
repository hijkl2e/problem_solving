#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, M{};
	cin >> N >> M;
	vector<int> A(N);
	for (int i = 0; i < N; ++i) {
		cin >> A[i];
	}
	priority_queue<ll, vector<ll>, greater<ll>> pq;
	for (int i = 0; i < N; ++i) {
		pq.push(A[i]);
	}
	while (M--) {
		ll x = pq.top(); pq.pop();
		ll y = pq.top(); pq.pop();
		pq.push(x + y);
		pq.push(x + y);
	}
	ll ans{};
	while (pq.size()) {
		ans += pq.top(); pq.pop();
	}
	cout << ans << "\n";
	return 0;
}
