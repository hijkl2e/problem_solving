#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, K{};
	cin >> N >> K;
	ll ans{};
	for (int i = 1, x = 1; i <= N; ++i) {
		if (x == i) {
			x *= 10;
		}
		ans = (x * ans + i) % K;
	}
	cout << ans << "\n";
	return 0;
}
