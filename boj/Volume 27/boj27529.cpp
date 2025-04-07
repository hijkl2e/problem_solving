#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ii = pair<ll, ll>;

const ll INF = 4e18;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	vector<ii> A(N);
	for (int i = 0; i < N; ++i) {
		cin >> A[i].first >> A[i].second;
	}
	ll x1 = INF, y1 = INF, x2 = -INF, y2 = -INF;
	for (auto &[x, y] : A) {
		x1 = min(x1, x);
		y1 = min(y1, y);
		x2 = max(x2, x);
		y2 = max(y2, y);
	}
	ll cnt = 2 * (x2 - x1 + y2 - y1 + 2);
	multiset<ll> B;
	for (auto &[x, y] : A) {
		B.insert(y);
	}
	y1 = INF, y2 = -INF;
	sort(A.begin(), A.end());
	ll ans{};
	for (auto &[x, y] : A) {
		if (x1 < x) {
			ans += y2 - y1 + 1;
			if (y2 < *B.begin()) {
				y1 = y2;
			} else if (*--B.end() < y1) {
				y2 = y1;
			} else {
				y1 = max(y1, *B.begin());
				y2 = min(y2, *--B.end());
			}
			ans += (x - x1 - 1) * (y2 - y1 + 1);
			x1 = x;
		}
		y1 = min(y1, y);
		y2 = max(y2, y);
		B.erase(B.find(y));
	}
	ans += y2 - y1 + 1;
	cout << cnt << " " << ans << "\n";
	return 0;
}
