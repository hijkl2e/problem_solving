#include <bits/stdc++.h>

using namespace std;

vector<int> B(6);
int ans;

void solve(int step, int x, int y, int z) {
	if (x > (z < 4 ? 10 : 15)) {
		return;
	}
	ans = max(ans, y);
	for (int i = step; i < 6; ++i) {
		solve(i, x + i, y + B[i], z + 1);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	for (int i = 1; i < 6; ++i) {
		cin >> B[i];
	}
	solve(1, 0, 0, 0);
	cout << ans << "\n";
	return 0;
}
