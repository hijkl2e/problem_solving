#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	ll N{}, M{};
	cin >> N >> M;
	vector<ll> A(N);
	for (int i = 0; i < N; ++i) {
		cin >> A[i];
	}
	ll ans{};
	for (int i = 1; i < (1 << N); ++i) {
		ll x = 1;
		for (int j = 0; j < N; ++j) {
			if (i & (1 << j)) {
				x *= A[j];
			}
		}
		ans += (__builtin_popcount(i) % 2 ? 1 : -1) * (M / x);
	}
	cout << ans << "\n";
	return 0;
}
