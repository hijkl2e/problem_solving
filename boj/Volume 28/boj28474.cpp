#include <bits/stdc++.h>

using namespace std;

int phi(int x) {
	int ret = 1;
	for (int i = 2; i * i <= x; ++i) {
		int y = 1;
		while (x % i == 0) {
			x /= i;
			y *= i;
		}
		ret *= y - y / i;
	}
	if (x > 1) {
		ret *= x - 1;
	}
	return ret;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T{};
	cin >> T;
	while (T--) {
		int N{};
		cin >> N;
		int ans = phi(N);
		if (N % 2 == 0) {
			ans += phi(N / 2);
		}
		if (N < 3) {
			ans = N - 1;
		}
		cout << ans << "\n";
	}
	return 0;
}
