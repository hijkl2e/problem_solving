#include <bits/stdc++.h>

using namespace std;

vector<string> grid(3);

bool solve() {
	for (int i = 0; i < 3; ++i) {
		int cnt{};
		for (int j = 0; j < 3; ++j) {
			if (grid[i][j] == grid[i][0]) {
				++cnt;
			}
		}
		if (cnt == 3 && grid[i][0] != '.') {
			return false;
		}
		cnt = 0;
		for (int j = 0; j < 3; ++j) {
			if (grid[j][i] == grid[0][i]) {
				++cnt;
			}
		}
		if (cnt == 3 && grid[0][i] != '.') {
			return false;
		}
	}
	int cnt{};
	for (int i = 0; i < 3; ++i) {
		if (grid[i][i] == grid[1][1]) {
			++cnt;
		}
	}
	if (cnt == 3 && grid[1][1] != '.') {
		return false;
	}
	cnt = 0;
	for (int i = 0; i < 3; ++i) {
		if (grid[i][2 - i] == grid[1][1]) {
			++cnt;
		}
	}
	if (cnt == 3 && grid[1][1] != '.') {
		return false;
	}
	return true;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T{};
	cin >> T;
	while (T--) {
		for (int i = 0; i < 3; ++i) {
			cin >> grid[i];
		}
		int X{}, O{};
		for (int i = 0; i < 3; ++i) {
			for (int j = 0; j < 3; ++j) {
				if (grid[i][j] == 'X') {
					++X;
				} else if (grid[i][j] == 'O') {
					++O;
				}
			}
		}
		if (X < O || abs(X - O) > 1) {
			cout << "no\n";
			continue;
		}
		bool yes = !X && !O;
		for (int i = 0; i < 3; ++i) {
			for (int j = 0; j < 3; ++j) {
				if (grid[i][j] == 'X' && X > O) {
					grid[i][j] = '.';
					if (solve()) {
						yes = true;
					}
					grid[i][j] = 'X';
				} else if (grid[i][j] == 'O' && X == O) {
					grid[i][j] = '.';
					if (solve()) {
						yes = true;
					}
					grid[i][j] = 'O';
				}
			}
		}
		cout << (yes ? "yes" : "no") << "\n";
	}
	return 0;
}
