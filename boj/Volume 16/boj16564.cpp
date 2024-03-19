#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, K{};
	cin >> N >> K;
	vector<int> A(N);
	for (int i = 0; i < N; ++i) {
		cin >> A[i];
	}
	ll lo = 1, hi = 2e9 + 1;
	while (lo + 1 < hi) {
		ll mid = (lo + hi) / 2;
		ll cnt{};
		for (int i = 0; i < N; ++i) {
			cnt += max(mid - A[i], 0LL);
		}
		if (cnt > K) {
			hi = mid;
		} else {
			lo = mid;
		}
	}
	cout << lo << "\n";
	return 0;
}
