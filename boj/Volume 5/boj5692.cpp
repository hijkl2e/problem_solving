#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	while (cin >> N, N) {
		int ans{};
		for (int i = 1, j = 1; N; i *= ++j) {
			ans += N % 10 * i;
			N /= 10;
		}
		cout << ans << "\n";
	}
	return 0;
}
