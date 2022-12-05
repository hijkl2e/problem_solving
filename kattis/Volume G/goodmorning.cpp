#include <bits/stdc++.h>

using namespace std;

set<int> S;

void solve(int x, int y) {
	if (y > 200 || (x == 0 && y == 0)) {
		return;
	}
	S.insert(y);
	solve(x, 10 * y + x);
	if (x % 3) {
		solve(x + 1, y);
	}
	if (x && (x < 7 || x == 8)) {
		solve(x < 7 ? x + 3 : 0, y);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	solve(1, 0);
	int T{};
	cin >> T;
	while (T--) {
		int K{};
		cin >> K;
		auto it = S.lower_bound(K);
		int ans = it == S.end() ? 1e9 : *it;
		if (it != S.begin() && ans - K > K - *--it) {
			ans = *it;
		}
		cout << ans << "\n";
	}
	return 0;
}
