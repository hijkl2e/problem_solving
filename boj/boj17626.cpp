#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	int ans = 4;
	for (int i = 0; 3 * i * i <= N; ++i) {
		for (int j = i; i * i + 2 * j * j <= N; ++j) {
			int x = N - i * i - j * j;
			int k = 1;
			while (k * k < x) {
				++k;
			}
			if (k * k == x) {
				ans = min(ans, j == 0 ? 1 : i == 0 ? 2 : 3);
			}
		}
	}
	cout << ans << "\n";
	return 0;
}
