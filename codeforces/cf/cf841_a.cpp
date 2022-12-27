#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T{};
	cin >> T;
	while (T--) {
		int N{};
		cin >> N;
		vector<int> A(N);
		for (int i = 0; i < N; ++i) {
			cin >> A[i];
		}
		ll ans = 1;
		for (int i = 0; i < N; ++i) {
			ans *= A[i];
		}
		ans = 2022 * (ans + N - 1);
		cout << ans << "\n";
	}
	return 0;
}
