#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	N = 1000 - N;
	int ans{};
	for (int i = 0, j = 500; j > 0; j /= ++i % 2 ? 5 : 2) {
		ans += N / j;
		N %= j;
	}
	cout << ans << "\n";
	return 0;
}
