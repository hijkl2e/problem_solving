#include <bits/stdc++.h>

using namespace std;

using ll = long long;

map<ll, int> D;
queue<ll> q;

void solve(ll x, int nd) {
	int &d = D[x];
	if (d == 0) {
		d = nd;
		q.push(x);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	ll N{};
	cin >> N;
	D[N] = 0;
	q.push(N);
	while (q.size()) {
		ll x = q.front(); q.pop();
		if (x == 1) {
			break;
		}
		int d = D[x];
		if (x % 3 == 0) {
			solve(x / 3, d + 1);
		}
		if (x % 2 == 0) {
			solve(x / 2, d + 1);
		}
		solve(x - 1, d + 1);
	}
	cout << D[1] << "\n";
	return 0;
}
