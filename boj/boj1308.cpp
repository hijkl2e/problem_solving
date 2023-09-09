#include <bits/stdc++.h>

using namespace std;

using iii = tuple<int, int, int>;

bool solve(int y) {
	return (y % 4 == 0 && y % 100) || y % 400 == 0;
}

int solve(int y, int m, int d) {
	static vector<int> A{
		-1, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31
	};
	int ret = d - 1;
	while (m-- > 1) {
		ret += A[m];
		if (m == 2 && solve(y)) {
			++ret;
		}
	}
	while (y-- > 1) {
		ret += 365 + solve(y);
	}
	return ret;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	iii a{}, b{};
	auto &[y1, m1, d1] = a;
	auto &[y2, m2, d2] = b;
	cin >> y1 >> m1 >> d1 >> y2 >> m2 >> d2;
	y1 += 1000;
	if (a <= b) {
		cout << "gg\n";
		return 0;
	}
	y1 -= 1000;
	int x = solve(y1, m1, d1);
	int y = solve(y2, m2, d2);
	cout << "D-" << y - x << "\n";
	return 0;
}
