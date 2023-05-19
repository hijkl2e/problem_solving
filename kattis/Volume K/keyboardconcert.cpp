#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9 + 7;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, M{};
	cin >> N >> M;
	vector<vector<int>> A(1001);
	for (int i = 0; i < N; ++i) {
		int K{};
		cin >> K;
		while (K--) {
			int x{};
			cin >> x;
			A[x].push_back(i);
		}
	}
	vector<int> B(M);
	for (int i = 0; i < M; ++i) {
		cin >> B[i];
	}
	vector<vector<int>> dp(M, vector<int>(N, INF));
	for (int i = 0; i < M; ++i) {
		int minv = i ? *min_element(dp[i - 1].begin(), dp[i - 1].end()) : INF;
		for (int x : A[B[i]]) {
			dp[i][x] = min(i ? dp[i - 1][x] : 0, minv + 1);
		}
	}
	int ans = *min_element(dp[M - 1].begin(), dp[M - 1].end());
	cout << ans << "\n";
	return 0;
}
