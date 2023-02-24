#include <bits/stdc++.h>

using namespace std;

int N, M, ans;
deque<bool> A(10);

void solve(int x, int d) {
	if (d) {
		ans = min(ans, d + abs(N - x));
	}
	if (d == 6) {
		return;
	}
	for (int i = 0; i < 10; ++i) {
		if (A[i]) {
			continue;
		}
		solve(10 * x + i, d + 1);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> N >> M;
	while (M--) {
		int x{};
		cin >> x;
		A[x] = true;
	}
	ans = abs(N - 100);
	solve(0, 0);
	cout << ans << "\n";
	return 0;
}
