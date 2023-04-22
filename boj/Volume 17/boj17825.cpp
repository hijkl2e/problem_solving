#include <bits/stdc++.h>

using namespace std;

int A[33]{
	1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20,
	32, 22, 23, 29, 25, 29, 27, 28, 29, 30, 31, 20, 32
};
int B[33]{
	0, 2, 4, 6, 8, 10, 12, 14, 16, 18, 20, 22, 24, 26, 28, 30, 32, 34, 36, 38,
	40, 13, 16, 19, 22, 24, 28, 27, 26, 25, 30, 35, 0
};
int C[33][6];
int D[10];
int E[4];

int solve(int n) {
	if (n == 10) {
		return 0;
	}
	int ret{};
	for (int i = 0; i < 4; ++i) {
		if (E[i] == 32) {
			continue;
		}
		int x = C[E[i]][D[n]];
		if (E[i] == 5 || E[i] == 10 || E[i] == 15) {
			x = C[E[i] == 5 ? 21 : E[i] == 10 ? 24 : 26][D[n] - 1];
		}
		if (x < 32 && count(E, E + 4, x)) {
			continue;
		}
		swap(E[i], x);
		ret = max(ret, B[E[i]] + solve(n + 1));
		swap(E[i], x);
	}
	return ret;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	for (int i = 0; i < 33; ++i) {
		C[i][0] = i;
		C[i][1] = A[i];
	}
	for (int j = 2; j < 6; ++j) {
		for (int i = 0; i < 33; ++i) {
			C[i][j] = C[C[i][j - 1]][1];
		}
	}
	for (int i = 0; i < 10; ++i) {
		cin >> D[i];
	}
	int ans = solve(0);
	cout << ans << "\n";
	return 0;
}
