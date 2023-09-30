#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T{};
	cin >> T;
	while (T--) {
		int K{}, M{};
		cin >> K >> M;
		int a{}, b{}, ans{};
		a = b = 1;
		for (int i = 3;; ++i) {
			int c = (a + b) % M;
			a = b, b = c;
			if (a == 1 && b == 0) {
				ans = i;
				break;
			}
		}
		cout << K << " " << ans << "\n";
	}
	return 0;
}
