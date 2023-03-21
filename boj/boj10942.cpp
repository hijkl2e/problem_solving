#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	vector<int> A(N);
	for (int i = 0; i < N; ++i) {
		cin >> A[i];
	}
	vector<deque<bool>> dp(N, deque<bool>(N));
	dp[N - 1][N - 1] = true;
	for (int i = N - 2; i >= 0; --i) {
		dp[i][i] = true;
		dp[i][i + 1] = A[i] == A[i + 1];
		for (int j = i + 2; j < N; ++j) {
			dp[i][j] = dp[i + 1][j - 1] && A[i] == A[j];
		}
	}
	int M{};
	cin >> M;
	while (M--) {
		int S{}, E{};
		cin >> S >> E;
		cout << dp[S - 1][E - 1] << "\n";
	}
	return 0;
}
