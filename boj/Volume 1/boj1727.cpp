#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9 + 7;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, M{};
	cin >> N >> M;
	vector<int> A(N + 1);
	vector<int> B(M + 1);
	for (int i = 1; i <= N; ++i) {
		cin >> A[i];
	}
	for (int i = 1; i <= M; ++i) {
		cin >> B[i];
	}
	if (N > M) {
		swap(N, M);
		swap(A, B);
	}
	sort(A.begin(), A.end());
	sort(B.begin(), B.end());
	vector<vector<int>> dp(N + 1, vector<int>(M + 1, INF));
	fill(dp[0].begin(), dp[0].end(), 0);
	for (int i = 1; i <= N; ++i) {
		for (int j = i; j <= M; ++j) {
			dp[i][j] = min(dp[i - 1][j - 1] + abs(A[i] - B[j]), dp[i][j - 1]);
		}
	}
	cout << dp[N][M] << "\n";
	return 0;
}
