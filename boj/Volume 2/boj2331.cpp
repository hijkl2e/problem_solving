#include <bits/stdc++.h>

using namespace std;

int solve(int x, int P) {
	int ret{};
	while (x) {
		int r = x % 10;
		int y = 1;
		for (int i = 0; i < P; ++i) {
			y *= r;
		}
		ret += y;
		x /= 10;
	}
	return ret;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int x{}, P{};
	cin >> x >> P;
	vector<int> A(3e5, -1);
	for (int i = 0; A[x] == -1; ++i) {
		A[x] = i;
		x = solve(x, P);
	}
	cout << A[x] << "\n";
	return 0;
}
