#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ii = pair<ll, ll>;

map<ll, int> D;
priority_queue<ii, vector<ii>, greater<ii>> pq;

void solve(ll v, int nd) {
	int &d = D[v];
	if (d == 0 || d > nd) {
		pq.push({d = nd, v});
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	ll N{};
	cin >> N;
	pq.push({D[N] = 0, N});
	while (pq.size()) {
		auto [d, u] = pq.top(); pq.pop();
		if (D[u] < d) {
			continue;
		} else if (u == 1) {
			break;
		}
		solve(u / 3, d + u % 3 + 1);
		solve(u / 2, d + u % 2 + 1);
	}
	cout << D[1] << "\n";
	return 0;
}
