#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	vector<int> A(7);
	for (int i = 1; i < 7; ++i) {
		cin >> A[i];
	}
	int ans = A[6] + A[5] + A[4];
	int x = min(11 * A[5], A[1]);
	A[1] -= x;
	x = 20 * A[4];
	int y = min(x / 4, A[2]);
	A[2] -= y;
	A[1] -= min(x - 4 * y, A[1]);
	ans += (A[3] + 3) / 4;
	A[3] %= 4;
	if (A[3]) {
		x = 9 * (4 - A[3]);
		y = min(7 - 2 * A[3], A[2]);
		A[2] -= y;
		A[1] -= min(x - 4 * y, A[1]);
	}
	ans += (A[2] + 8) / 9;
	A[2] %= 9;
	if (A[2]) {
		A[1] -= min(4 * (9 - A[2]), A[1]);
	}
	ans += (A[1] + 35) / 36;
	cout << ans << "\n";
	return 0;
}
