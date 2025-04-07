#include <bits/stdc++.h>

using namespace std;

using ll = long long;

deque<bool> sieve() {
	deque<bool> p(4e6, true);
	p[0] = p[1] = false;
	for (int i = 2; i < p.size(); ++i) {
		if (p[i]) {
			for (int j = 2 * i; j < p.size(); j += i) {
				p[j] = false;
			}
		}
	}
	return p;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, K{}, M{};
	cin >> N >> K >> M;
	deque<bool> p = sieve();
	vector<ll> P;
	for (int i = 2; i < p.size(); ++i) {
		if (p[i]) {
			P.push_back(i);
		}
	}
	vector<int> A(P.size());
	for (int i = 0; i < P.size(); ++i) {
		for (ll j = P[i]; j <= N; j *= P[i]) {
			A[i] += N / j - (N - K) / j - K / j;
		}
	}
	ll ans = 1;
	for (int i = 0; i < P.size(); ++i) {
		while (A[i]--) {
			ans = ans * P[i] % M;
		}
	}
	cout << ans << "\n";
	return 0;
}
