#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, L{}, D{};
	cin >> N >> L >> D;
	int ans{};
	for (int i = 0;; ++i) {
		int t = i * D;
		if (t % (L + 5) >= L || t >= N * (L + 5) - 5) {
			ans = t;
			break;
		}
	}
	cout << ans << "\n";
	return 0;
}
