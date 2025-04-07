#include <bits/stdc++.h>

using namespace std;

int solve(int x) {
	int ret = x;
	for (int i = 0; i < 3; ++i) {
		x = x % 1000 * 10 + x / 1000;
		ret = min(ret, x);
	}
	return ret;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int x{};
	for (int i = 0; i < 4; ++i) {
		int y{};
		cin >> y;
		x = 10 * x + y;
	}
	x = solve(x);
	vector<int> A;
	for (int i = 1111; i <= 9999; ++i) {
		if (solve(i) == i) {
			A.push_back(i);
		}
	}
	int ans = find(A.begin(), A.end(), x) - A.begin() + 1;
	cout << ans << "\n";
	return 0;
}
