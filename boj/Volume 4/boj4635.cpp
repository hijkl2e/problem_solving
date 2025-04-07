#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	while (cin >> N, N != -1) {
		int prev_t{}, ans{};
		while (N--) {
			int s{}, t{};
			cin >> s >> t;
			ans += s * (t - prev_t);
			prev_t = t;
		}
		cout << ans << " miles\n";
	}
	return 0;
}
