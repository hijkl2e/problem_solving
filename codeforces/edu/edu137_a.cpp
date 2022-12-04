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
		for (int i = 0; i < N; ++i) {
			int x{};
			cin >> x;
		}
		N = 10 - N;
		int ans = 6 * N * (N - 1) / 2;
		cout << ans << "\n";
	}
	return 0;
}
