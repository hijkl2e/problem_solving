#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const ll INF = 4e18;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T{};
	cin >> T;
	while (T--) {
		int N{};
		cin >> N;
		vector<ll> A(N);
		for (int i = 0; i < N; ++i) {
			cin >> A[i];
		}
		sort(A.begin(), A.end());
		ll ans = INF;
		for (int i = 0; i + N / 2 < N; ++i) {
			if (A[i] == A[i + N / 2]) {
				ans = A[i];
				break;
			}
		}
		if (ans == INF) {
			cout << "SYJKGW\n";
		} else {
			cout << ans << "\n";
		}
	}
	return 0;
}
