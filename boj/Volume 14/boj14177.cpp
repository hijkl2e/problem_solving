#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9 + 7;

vector<vector<int>> A, dp;

void solve(int L, int R, int optL, int optR) {
	if (L > R) {
		return;
	}
	int j = (L + R) / 2;
	dp[1][j] = INF;
	int opt{};
	for (int k = optL; k <= optR && k < j; ++k) {
		int val = dp[0][k] + A[j][k + 1];
		if (dp[1][j] > val) {
			dp[1][j] = val;
			opt = k;
		}
	}
	solve(L, j - 1, optL, opt);
	solve(j + 1, R, opt, optR);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, K{};
	cin >> N >> K;
	cin.ignore();
	A.resize(N + 1);
	for (int i = 1; i <= N; ++i) {
		string s;
		getline(cin, s);
		A[i].resize(i + 1);
		for (int j = 1; j < i; ++j) {
			A[i][j] = s[2 * j - 2] - '0';
		}
	}
	for (int i = 1; i <= N; ++i) {
		int sum{};
		for (int j = i - 1; j > 0; --j) {
			sum += A[i][j];
			A[i][j] = A[i - 1][j] + sum;
		}
	}
	dp.assign(2, vector<int>(N + 1, INF));
	dp[0][0] = 0;
	for (int i = 1; i <= K; ++i) {
		solve(i, N - K + i, i - 1, N - K + i - 1);
		copy(dp[1].begin(), dp[1].end(), dp[0].begin());
	}
	cout << dp[0][N] << "\n";
	return 0;
}
