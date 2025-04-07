#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int H{}, C{};
	cin >> H >> C;
	vector<ll> A(C);
	vector<ll> D(C);
	for (int i = 0; i < C; ++i) {
		cin >> A[i] >> D[i];
	}
	ll lo = 0, hi = 2e14;
	while (lo + 1 < hi) {
		ll mid = (lo + hi) / 2;
		ll cnt{};
		for (int i = 0; i < C; ++i) {
			if (mid < A[i]) {
				cnt = -1;
				break;
			}
			cnt += (mid - A[i]) / D[i];
		}
		if (cnt < H) {
			lo = mid;
		} else {
			hi = mid;
		}
	}
	cout << hi << "\n";
	return 0;
}
