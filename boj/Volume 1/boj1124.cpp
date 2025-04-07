#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int A{}, B{};
	cin >> A >> B;
	int ans{};
	for (int i = A; i <= B; ++i) {
		int k = i, cnt{};
		for (int j = 2; j * j <= k; ++j) {
			while (k % j == 0) {
				k /= j;
				++cnt;
			}
		}
		if (k > 1) {
			++cnt;
		}
		if (cnt == 2 || cnt == 3 || cnt == 5 || cnt == 7 || cnt == 11 || cnt == 13) {
			++ans;
		}
	}
	cout << ans << "\n";
	return 0;
}
