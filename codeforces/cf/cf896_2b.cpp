#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const ll INF = 4e18;

ll dist(ll x1, ll y1, ll x2, ll y2) {
	return abs(x2 - x1) + abs(y2 - y1);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T{};
	cin >> T;
	while (T--) {
		int N{}, K{}, a{}, b{};
		cin >> N >> K >> a >> b;
		vector<int> x(N + 1);
		vector<int> y(N + 1);
		for (int i = 1; i <= N; ++i) {
			cin >> x[i] >> y[i];
		}
		ll d1 = INF, d2 = INF;
		for (int i = 1; i <= K; ++i) {
			d1 = min(d1, dist(x[a], y[a], x[i], y[i]));
			d2 = min(d2, dist(x[b], y[b], x[i], y[i]));
		}
		ll ans = min(dist(x[a], y[a], x[b], y[b]), d1 + d2);
		cout << ans << "\n";
	}
	return 0;
}
