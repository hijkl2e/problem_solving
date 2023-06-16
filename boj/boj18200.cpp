#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, K{};
	cin >> N >> K;
	K = min(N, K);
	vector<int> A(N);
	for (int i = 0; i < N; ++i) {
		cin >> A[i];
	}
	sort(A.begin(), A.end());
	ll lo = 0, hi = 1e10;
	while (lo + 1 < hi) {
		ll mid = (lo + hi) / 2;
		ll cnt{};
		for (int i = 0; i < K; ++i) {
			if (mid < A[i]) {
				continue;
			}
			cnt += (mid - A[i]) / (2 * A[i]) * 4 + 5;
		}
		if (cnt < N) {
			lo = mid;
		} else {
			hi = mid;
		}
	}
	cout << hi << "\n";
	return 0;
}
