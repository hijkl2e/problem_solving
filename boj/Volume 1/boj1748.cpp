#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	int ans{};
	for (int i = 1, j = 9;; ++i, j *= 10) {
		if (N <= j) {
			ans += i * N;
			break;
		}
		ans += i * j;
		N -= j;
	}
	cout << ans << "\n";
	return 0;
}
