#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T{};
	cin >> T;
	while (T--) {
		int N{};
		cin >> N;
		int ans = N;
		while (N > 1) {
			if (N % 2) {
				N = 3 * N + 1;
			} else {
				N /= 2;
			}
			ans = max(ans, N);
		}
		cout << ans << "\n";
	}
	return 0;
}
