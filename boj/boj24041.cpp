#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int N, G, K;
vector<int> S, L, O;

bool solve(ll x) {
	ll sum{};
	priority_queue<ll, vector<ll>, greater<ll>> pq;
	for (int i = 0; i < N && sum <= G; ++i) {
		ll val = S[i] * max(1LL, x - L[i]);
		if (O[i]) {
			pq.push(val);
			if (pq.size() > K) {
				sum += pq.top();
				pq.pop();
			}
		} else {
			sum += val;
		}
	}
	return sum <= G;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> N >> G >> K;
	S.resize(N);
	L.resize(N);
	O.resize(N);
	for (int i = 0; i < N; ++i) {
		cin >> S[i] >> L[i] >> O[i];
	}
	ll lo = 1, hi = 2e9 + 1;
	while (lo + 1 < hi) {
		ll mid = (lo + hi) / 2;
		if (solve(mid)) {
			lo = mid;
		} else {
			hi = mid;
		}
	}
	cout << lo << "\n";
	return 0;
}
