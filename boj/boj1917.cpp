#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> A(6, vector<int>(6));

int sum(int x, bool f) {
	if (x == -1 || x == 6) {
		return 0;
	}
	int ret{}, p = -1;
	for (int i = 0; i < 6; ++i) {
		if (f ? A[x][i] : A[i][x]) {
			if (p == -1 || p == i - 1) {
				p = i;
				++ret;
			} else {
				return -1;
			}
		}
	}
	return ret;
}

bool solve() {
	for (int i = 0; i < 5; ++i) {
		for (int j = 0; j < 5; ++j) {
			if (A[i][j] && A[i][j + 1] && A[i + 1][j] && A[i + 1][j + 1]) {
				return false;
			}
		}
	}
	int maxv{};
	for (int k = 0; k < 2; ++k) {
		for (int i = 0; i < 6; ++i) {
			int res = sum(i, k);
			if (res == -1 || res > 4) {
				return false;
			} else if (res == 4) {
				return sum(i - 1, k) == 1 && sum(i + 1, k) == 1;
			}
			maxv = max(maxv, res);
		}
	}
	if (maxv == 2) {
		return true;
	}
	for (int k = 0; k < 2; ++k) {
		for (int i = 0; i < 6; ++i) {
			if (sum(i, k) == 3 && sum(i - 1, k) + sum(i + 1, k) == 3) {
				return true;
			}
		}
	}
	return false;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	for (int k = 0; k < 3; ++k) {
		for (int i = 0; i < 6; ++i) {
			for (int j = 0; j < 6; ++j) {
				cin >> A[i][j];
			}
		}
		cout << (solve() ? "yes" : "no") << "\n";
	}
	return 0;
}
