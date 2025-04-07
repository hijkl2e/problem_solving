#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	ll N{}, M{};
	cin >> N >> M;
	vector<ll> L(N);
	for (int i = 0; i < N; ++i) {
		cin >> L[i];
	}
	vector<ll> A(N);
	for (int i = 0; i < N; ++i) {
		cin >> A[i];
	}
	vector<ll> B(N);
	for (int i = 0; i < N; ++i) {
		ll lo = L[i], hi = 2e9;
		while (lo + 1 < hi) {
			ll mid = (lo + hi) / 2;
			if (mid * (mid - 1) / 2 - L[i] * (L[i] - 1) / 2 <= A[i]) {
				lo = mid;
			} else {
				hi = mid;
			}
		}
		B[i] = lo;
	}
	ll lo = 1, hi = 1e12;
	while (lo + 1 < hi) {
		ll mid = (lo + hi) / 2;
		ll sum{};
		for (int i = 0; i < N; ++i) {
			sum += max(mid - B[i], 0LL);
		}
		if (sum <= M) {
			lo = mid;
		} else {
			hi = mid;
		}
	}
	ll ans = *max_element(L.begin(), L.end()) > lo ? -1 : lo;
	cout << ans << "\n";
	return 0;
}
