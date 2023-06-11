#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T{};
	cin >> T;
	while (T--) {
		vector<ll> A(6);
		for (int i = 0; i < 6; ++i) {
			cin >> A[i];
		}
		for (int i = 0; i < 6; i += 2) {
			if (A[i] < A[i + 1]) {
				swap(A[i], A[i + 1]);
			}
		}
		for (int i = 2; i < 6; i += 2) {
			if (A[i] > A[0]) {
				swap(A[i], A[0]);
				swap(A[i + 1], A[1]);
			}
		}
		ll ans = 4e18;
		for (int i = 0; i < 2; ++i) {
			for (int j = 2; j < 4; ++j) {
				for (int k = 4; k < 6; ++k) {
					ans = min(ans, (A[i] + A[j] + A[k]) * max({A[i ^ 1], A[j ^ 1], A[k ^ 1]}));
					ans = min(ans, max(A[i], A[j] + A[k]) * (A[i ^ 1] + max(A[j ^ 1], A[k ^ 1])));
				}
			}
		}
		for (int i = 2; i < 6; ++i) {
			ans = min(ans, (A[0] + A[i]) * max(A[1] + A[(i ^ 6) | 1], A[i ^ 1]));
		}
		cout << ans << "\n";
	}
	return 0;
}
