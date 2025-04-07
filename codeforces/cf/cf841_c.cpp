#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T{};
	cin >> T;
	while (T--) {
		ll N{};
		cin >> N;
		vector<int> A(N);
		for (int i = 0; i < N; ++i) {
			cin >> A[i];
		}
		int sz = 1;
		while (sz <= N) {
			sz *= 2;
		}
		vector<int> B(sz);
		B[0] = 1;
		int x{};
		ll ans = N * (N + 1) / 2;
		for (int i = 0; i < N; ++i) {
			x ^= A[i];
			for (int j = 0; j * j < sz; ++j) {
				ans -= B[x ^ (j * j)];
			}
			++B[x];
		}
		cout << ans << "\n";
	}
	return 0;
}
