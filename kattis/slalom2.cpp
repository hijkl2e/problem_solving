#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	ll w{}, vh{}, N{};
	cin >> w >> vh >> N;
	vector<ll> x(N);
	vector<ll> y(N);
	for (int i = 0; i < N; ++i) {
		cin >> x[i] >> y[i];
	}
	int M{};
	cin >> M;
	vector<int> A(M);
	for (int i = 0; i < M; ++i) {
		cin >> A[i];
	}
	sort(A.begin(), A.end());
	ll lo = 0, hi = 1e6 + 1;
	while (lo + 1 < hi) {
		ll mid = (lo + hi) / 2;
		ll l = mid * x[0], r = mid * (x[0] + w);
		for (int i = 1; i < N && l <= r; ++i) {
			l -= vh * (y[i] - y[i - 1]);
			r += vh * (y[i] - y[i - 1]);
			l = max(l, mid * x[i]);
			r = min(r, mid * (x[i] + w));
		}
		if (l <= r) {
			lo = mid;
		} else {
			hi = mid;
		}
	}
	auto it = upper_bound(A.begin(), A.end(), lo);
	if (it == A.begin()) {
		cout << "IMPOSSIBLE\n";
	} else {
		cout << *--it << "\n";
	}
	return 0;
}
