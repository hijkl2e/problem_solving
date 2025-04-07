#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, r{}, c{};
	cin >> N >> r >> c;
	int ans{};
	while (N--) {
		if (r >= (1 << N) && c >= (1 << N)) {
			ans += 3 * (1 << (2 * N));
		} else if (r >= (1 << N)) {
			ans += 2 * (1 << (2 * N));
		} else if (c >= (1 << N)) {
			ans += 1 << (2 * N);
		}
		r %= 1 << N;
		c %= 1 << N;
	}
	cout << ans << "\n";
	return 0;
}
