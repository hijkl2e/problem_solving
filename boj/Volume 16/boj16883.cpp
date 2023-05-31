#include <bits/stdc++.h>

using namespace std;

vector<string> B;
int dp[21][21][21][21];

int solve(int x1, int y1, int x2, int y2) {
	if (x1 > x2 || y1 > y2) {
		return 0;
	}
	int &ret = dp[x1][y1][x2][y2];
	if (ret != -1) {
		return ret;
	}
	deque<bool> vst(256);
	for (int i = x1; i <= x2; ++i) {
		for (int j = y1; j <= y2; ++j) {
			if (B[i][j] == '.') {
				continue;
			}
			int k{};
			if (B[i][j] == 'L') {
				k = solve(x1, y1, i - 1, y2) ^ solve(i + 1, y1, x2, y2);
			} else if (B[i][j] == 'R') {
				k = solve(x1, y1, x2, j - 1) ^ solve(x1, j + 1, x2, y2);
			} else if (B[i][j] == 'X') {
				k = solve(x1, y1, i - 1, j - 1) ^ solve(x1, j + 1, i - 1, y2)
						^ solve(i + 1, y1, x2, j - 1) ^ solve(i + 1, j + 1, x2, y2);
			}
			vst[k] = true;
		}
	}
	ret = 0;
	for (int i = 0; vst[i]; ++i) {
		ret = i + 1;
	}
	return ret;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, M{};
	cin >> N >> M;
	cin.ignore();
	vector<string> A(N);
	for (int i = 0; i < N; ++i) {
		getline(cin, A[i]);
	}
	int sz = (N + M) / 2;
	B.assign(sz, string(sz, '.'));
	for (int i = 0; i < N; ++i) {
		for (int j = i % 2; j < M; j += 2) {
			B[(i + j) / 2][(N - i + j - 1) / 2] = A[i][j];
		}
	}
	memset(dp, -1, sizeof dp);
	int ans = solve(0, 0, sz - 1, sz - 1);
	B.assign(sz, string(sz, '.'));
	for (int i = 0; i < N; ++i) {
		for (int j = (i + 1) % 2; j < M; j += 2) {
			B[(i + j) / 2][(N - i + j - 1) / 2] = A[i][j];
		}
	}
	memset(dp, -1, sizeof dp);
	ans ^= solve(0, 0, sz - 1, sz - 1);
	cout << (ans ? "koosaga" : "cubelover") << "\n";
	return 0;
}
