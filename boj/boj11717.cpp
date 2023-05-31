#include <bits/stdc++.h>

using namespace std;

vector<string> A;
int dp[21][21][21][21];

int solve(int x1, int y1, int x2, int y2) {
	if (x1 > x2 || y1 > y2) {
		return 0;
	}
	int &ret = dp[x1][y1][x2][y2];
	if (ret != -1) {
		return ret;
	}
	ret = 0;
	deque<bool> vst(512);
	for (int i = x1; i <= x2; ++i) {
		for (int j = y1; j <= y2; ++j) {
			if (A[i][j] == 'X') {
				continue;
			}
			int res = solve(x1, y1, i - 1, j - 1) ^ solve(x1, j + 1, i - 1, y2)
					^ solve(i + 1, y1, x2, j - 1) ^ solve(i + 1, j + 1, x2, y2);
			vst[res] = true;
		}
	}
	for (int i = 0; vst[i]; ++i) {
		ret = i + 1;
	}
	return ret;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int R{}, C{};
	cin >> R >> C;
	cin.ignore();
	A.resize(R);
	for (int i = 0; i < R; ++i) {
		getline(cin, A[i]);
	}
	memset(dp, -1, sizeof dp);
	cout << (solve(0, 0, R - 1, C - 1) ? "First" : "Second") << "\n";
	return 0;
}
