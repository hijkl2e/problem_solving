#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, K{};
	while (cin >> N >> K, N) {
		ll ans = 1;
		K = min(K, N - K);
		for (int i = 1; i <= K; ++i) {
			ans *= N - i + 1;
			ans /= i;
		}
		cout << ans << "\n";
	}
	return 0;
}
