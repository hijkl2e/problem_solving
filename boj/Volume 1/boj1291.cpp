#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	bool f1 = N == 4 || N > 5;
	int x = N, sum{};
	while (x) {
		sum += x % 10;
		x /= 10;
	}
	f1 &= sum % 2 == 1;
	bool f2 = N == 2 || N == 4;
	int cnt = N == 1 ? -1 : 0;
	for (int i = 2; i * i <= N; ++i) {
		if (N % i) {
			continue;
		}
		while (N % i == 0) {
			N /= i;
		}
		++cnt;
	}
	if (N > 1) {
		++cnt;
	}
	if (cnt % 2 == 0) {
		f2 = true;
	}
	int ans = f1 ? f2 ? 4 : 1 : f2 ? 2 : 3;
	cout << ans << "\n";
	return 0;
}
