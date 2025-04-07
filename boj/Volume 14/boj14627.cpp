#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, M{};
	cin >> N >> M;
	vector<int> A(N);
	for (int i = 0; i < N; ++i) {
		cin >> A[i];
	}
	ll lo = 0, hi = 1e9 + 1;
	while (lo + 1 < hi) {
		int mid = (lo + hi) / 2;
		ll cnt{};
		for (int i = 0; i < N; ++i) {
			cnt += A[i] / mid;
		}
		if (cnt < M) {
			hi = mid;
		} else {
			lo = mid;
		}
	}
	ll ans = accumulate(A.begin(), A.end(), 0LL) - lo * M;
	cout << ans << "\n";
	return 0;
}
