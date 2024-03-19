#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, K{};
	cin >> N >> K;
	int ans{};
	for (int i = 1; i <= N; ++i) {
		int x = i;
		for (int j = 2; j <= K; ++j) {
			while (x % j == 0) {
				x /= j;
			}
		}
		if (x == 1) {
			++ans;
		}
	}
	cout << ans << "\n";
	return 0;
}
