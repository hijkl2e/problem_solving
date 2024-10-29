#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int K{};
	cin >> K;
	int cnt{};
	for (int i = 2; i * i <= K; ++i) {
		while (K % i == 0) {
			K /= i;
			++cnt;
		}
	}
	if (K > 1) {
		++cnt;
	}
	int ans = cnt > 1 ? (32 - __builtin_clz(cnt - 1)) : 0;
	cout << ans << "\n";
	return 0;
}
