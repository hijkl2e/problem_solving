#include <bits/stdc++.h>

using namespace std;

using ll = long long;

deque<bool> sieve() {
	deque<bool> p(159705, true);
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

vector<int> P;

ll solve(ll X, int idx, __int128 val) {
	ll ret = X / (val * val);
	for (int i = idx; i < P.size(); ++i) {
		__int128 y = val * P[i];
		if (X < y * y) {
			break;
		}
		ret -= solve(X, i + 1, y);
	}
	return ret;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	deque<bool> p = sieve();
	for (int i = 2; i < p.size(); ++i) {
		if (p[i]) {
			P.push_back(i);
		}
	}
	ll K{};
	cin >> K;
	ll lo = 0, hi = 3e10;
	while (lo + 1 < hi) {
		ll mid = (lo + hi) / 2;
		if (mid - solve(mid, 0, 1) < K) {
			lo = mid;
		} else {
			hi = mid;
		}
	}
	cout << hi << "\n";
	return 0;
}
