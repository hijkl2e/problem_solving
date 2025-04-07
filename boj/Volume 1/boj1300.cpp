#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	ll N{}, K{};
	cin >> N >> K;
	ll lo = 1, hi = N * N + 1;
	while (lo + 1 < hi) {
		ll mid = (lo + hi) / 2;
		ll cnt{};
		for (int i = 1; i <= N; ++i) {
			cnt += min((mid - 1) / i, N);
		}
		if (cnt < K) {
			lo = mid;
		} else {
			hi = mid;
		}
	}
	cout << lo << "\n";
	return 0;
}
