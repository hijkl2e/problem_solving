#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T{};
	cin >> T;
	for (int tc = 1; tc <= T; ++tc) {
		int P{}, K{}, L{};
		cin >> P >> K >> L;
		vector<int> A(L);
		for (int i = 0; i < L; ++i) {
			cin >> A[i];
		}
		sort(A.rbegin(), A.rend());
		ll ans{};
		for (int i = 0; i < L; ++i) {
			ans += (i / K + 1) * A[i];
		}
		cout << "Case #" << tc << ": " << ans << "\n";
	}
	return 0;
}
