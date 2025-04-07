#include <bits/stdc++.h>

using namespace std;

int solve(int x, int y) {
	int ret{};
	while (x) {
		ret += x % y;
		x /= y;
	}
	return ret;
}

bool solve(int x) {
	int res1 = solve(x, 10);
	int res2 = solve(x, 12);
	int res3 = solve(x, 16);
	return res1 == res2 && res2 == res3;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	for (int i = 1000; i < 10000; ++i) {
		if (solve(i)) {
			cout << i << "\n";
		}
	}
	return 0;
}
