#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	int lo = 1, hi = N + 1;
	int ans = -1;
	while (ans == -1) {
		int m2 = (lo + hi) / 2;
		int m1 = (lo + m2) / 2;
		int m3 = (m2 + hi) / 2;
		cout << "Q " << lo << " " << m2 - 1 << " " << m1 << " " << m3 - 1 << endl;
		int w1{}, w2{};
		cin >> w1 >> w2;
		if (w1 == w2) {
			if (w1) {
				ans = m1 == m2 - 1 ? m1 : -1;
				lo = m1 - 1, hi = m2 + 1;
			} else {
				ans = m3 == hi - 1 ? m3 : -1;
				lo = m3 - 1, hi = min(hi, N) + 1;
			}
		} else {
			if (w1) {
				ans = lo == m1 - 1 ? lo : -1;
				lo = max(lo - 1, 1), hi = m1 + 1;
			} else {
				ans = m2 == m3 - 1 ? m2 : -1;
				lo = m2 - 1, hi = m3 + 1;
			}
		}
	}
	cout << "A " << ans << endl;
	return 0;
}
