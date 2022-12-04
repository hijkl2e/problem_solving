#include <bits/stdc++.h>

using namespace std;

int solve(int x) {
	int ret = 1;
	while (x) {
		if (x % 10) {
			ret *= x % 10;
		}
		x /= 10;
	}
	return ret;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int x{};
	cin >> x;
	while (x >= 10) {
		x = solve(x);
	}
	cout << x << "\n";
	return 0;
}
