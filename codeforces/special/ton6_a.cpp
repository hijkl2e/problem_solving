#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T{};
	cin >> T;
	while (T--) {
		int N{}, K{}, x{};
		cin >> N >> K >> x;
		if (min(N, x + 1) < K) {
			cout << "-1\n";
			continue;
		}
		int ans = K * (K - 1) / 2 + (N - K) * (x == K ? K - 1 : x);
		cout << ans << "\n";
	}
	return 0;
}
