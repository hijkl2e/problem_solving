#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	vector<vector<int>> A(N, vector<int>(N));
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			cin >> A[i][j];
		}
	}
	vector<deque<bool>> dp(N, deque<bool>(N));
	dp[N - 1][N - 1] = true;
	for (int i = N - 1; i >= 0; --i) {
		for (int j = N - 1; j >= 0; --j) {
			if (A[i][j] == -1) {
				continue;
			}
			dp[i][j] |= i + A[i][j] < N && dp[i + A[i][j]][j];
			dp[i][j] |= j + A[i][j] < N && dp[i][j + A[i][j]];
		}
	}
	cout << (dp[0][0] ? "HaruHaru" : "Hing") << "\n";
	return 0;
}
