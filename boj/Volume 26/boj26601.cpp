#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const ll MOD = 2000003;

deque<bool> sieve() {
	deque<bool> p(1500001, true);
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
	deque<bool> p = sieve();
	vector<ll> A;
	for (int i = 2; i < p.size(); ++i) {
		if (p[i]) {
			A.push_back(i);
		}
	}
	for (int i = 0; i < A.size(); ++i) {
		ll x = A[i] * A[i];
		if (x < 1500001) {
			A.push_back(x);
		}
	}
	sort(A.begin(), A.end());
	int N{};
	cin >> N;
	ll ans = 1;
	for (int i = 0; i < N; ++i) {
		ans = ans * A[i] % MOD;
	}
	cout << ans << "\n";
	return 0;
}
