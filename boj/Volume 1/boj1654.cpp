#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int K{}, N{};
	cin >> K >> N;
	vector<ll> A(K);
	for (int i = 0; i < K; ++i) {
		cin >> A[i];
	}
	ll lo = 1, hi = 1LL << 31;
	while (lo + 1 < hi) {
		ll mid = (lo + hi) / 2;
		ll cnt{};
		for (int i = 0; i < K; ++i) {
			cnt += A[i] / mid;
		}
		if (cnt < N) {
			hi = mid;
		} else {
			lo = mid;
		}
	}
	cout << lo << "\n";
	return 0;
}
