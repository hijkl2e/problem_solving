#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	int prev_t{}, prev_d{};
	cin >> prev_t >> prev_d;
	int ans{};
	while (--N) {
		int t{}, d{};
		cin >> t >> d;
		ans = max(ans, (d - prev_d) / (t - prev_t));
		prev_t = t;
		prev_d = d;
	}
	cout << ans << "\n";
	return 0;
}
