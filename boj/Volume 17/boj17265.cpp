#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9 + 7;

int calc(int x, char op, int y) {
	int ret{};
	if (op == '+') {
		ret = x + y;
	} else if (op == '-') {
		ret = x - y;
	} else if (op == '*') {
		ret = x * y;
	}
	return ret;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	vector<vector<char>> A(N, vector<char>(N));
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			cin >> A[i][j];
		}
	}
	vector<vector<int>> dp1(N, vector<int>(N, -INF));
	vector<vector<int>> dp2(N, vector<int>(N, INF));
	dp1[0][0] = dp2[0][0] = A[0][0] - '0';
	for (int i = 0; i < N; ++i) {
		for (int j = i % 2; j < N; j += 2) {
			if (i > 1) {
				dp1[i][j] = max(dp1[i][j], calc(dp1[i - 2][j], A[i - 1][j], A[i][j] - '0'));
				dp2[i][j] = min(dp2[i][j], calc(dp2[i - 2][j], A[i - 1][j], A[i][j] - '0'));
			}
			if (j > 1) {
				dp1[i][j] = max(dp1[i][j], calc(dp1[i][j - 2], A[i][j - 1], A[i][j] - '0'));
				dp2[i][j] = min(dp2[i][j], calc(dp2[i][j - 2], A[i][j - 1], A[i][j] - '0'));
			}
			if (i && j) {
				dp1[i][j] = max(dp1[i][j], calc(dp1[i - 1][j - 1], A[i - 1][j], A[i][j] - '0'));
				dp2[i][j] = min(dp2[i][j], calc(dp2[i - 1][j - 1], A[i - 1][j], A[i][j] - '0'));
				dp1[i][j] = max(dp1[i][j], calc(dp1[i - 1][j - 1], A[i][j - 1], A[i][j] - '0'));
				dp2[i][j] = min(dp2[i][j], calc(dp2[i - 1][j - 1], A[i][j - 1], A[i][j] - '0'));
			}
		}
	}
	cout << dp1[N - 1][N - 1] << " " << dp2[N - 1][N - 1] << "\n";
	return 0;
}
