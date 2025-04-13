#include <bits/stdc++.h>

using namespace std;

int K, X, Y, N;
vector<vector<int>> A;

void solve(int x, int y, int k, int q) {
	int L = (1 << k);
	if (q == -1) {
		q = 2 * (X >= x + L) + (Y >= y + L);
	}
	if (k) {
		solve(x + L / 2, y + L / 2, k - 1, q);
	} else {
		++N;
	}
	for (int i = 0; i < 2; ++i) {
		for (int j = 0; j < 2; ++j) {
			if (q == 2 * i + j) {
				continue;
			}
			if (k) {
				solve(x + i * L, y + j * L, k - 1, (2 * i + j) ^ 3);
			} else {
				A[x + i][y + j] = N;
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> K >> Y >> X;
	X = (1 << K) - X, --Y;
	A.assign(1 << K, vector<int>(1 << K, -1));
	int x{}, y{};
	for (int i = K - 1; i >= 0; --i) {
		solve(x, y, i, -1);
		int L = (1 << i);
		if (X >= x + L) {
			x += L;
		}
		if (Y >= y + L) {
			y += L;
		}
	}
	for (int i = 0; i < (1 << K); ++i) {
		for (int j = 0; j < (1 << K); ++j) {
			cout << A[i][j] << (j == (1 << K) - 1 ? "\n" : " ");
		}
	}
	return 0;
}
