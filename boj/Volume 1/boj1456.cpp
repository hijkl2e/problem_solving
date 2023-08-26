#include <bits/stdc++.h>

using namespace std;

using ll = long long;

deque<bool> sieve() {
	deque<bool> p(10000001, true);
	p[0] = p[1] = false;
	for (int i = 2; i * i < p.size(); ++i) {
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
	vector<int> P;
	for (int i = 2; i < p.size(); ++i) {
		if (p[i]) {
			P.push_back(i);
		}
	}
	ll a{}, b{};
	cin >> a >> b;
	vector<ll> A(P.begin(), P.end());
	int ans{};
	while (A.size()) {
		for (int i = A.size() - 1; i >= 0; --i) {
			if (A[i] > b / P[i]) {
				A.pop_back();
				continue;
			}
			A[i] *= P[i];
		}
		ans += A.end() - lower_bound(A.begin(), A.end(), a);
	}
	cout << ans << "\n";
	return 0;
}
