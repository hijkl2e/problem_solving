#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	ll N{}, M{};
	cin >> N >> M;
	vector<int> A(N);
	vector<int> B(N);
	vector<int> C(N);
	for (int i = 0; i < N; ++i) {
		cin >> A[i] >> B[i] >> C[i];
	}
	ll lo = 0, hi = 4e18;
	while (lo + 1 < hi) {
		ll mid = (lo + hi) / 2;
		ll x = M, y = mid;
		for (int i = 0; i < N && y > 0; ++i) {
			if (A[i] == 1) {
				y -= (C[i] - 1) / x * B[i];
			} else {
				y = min(y + C[i], mid);
				x += B[i];
			}
		}
		if (y > 0) {
			hi = mid;
		} else {
			lo = mid;
		}
	}
	cout << hi << "\n";
	return 0;
}
