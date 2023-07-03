#include <bits/stdc++.h>

using namespace std;

using ii = pair<int, int>;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, M{};
	cin >> N >> M;
	vector<int> A(M);
	for (int i = 0; i < M; ++i) {
		cin >> A[i];
	}
	vector<vector<ii>> B(M);
	for (int i = 0; i < M; ++i) {
		B[i].resize(A[i] / 2);
		for (int j = 0; j < B[i].size(); ++j) {
			cin >> B[i][j].first >> B[i][j].second;
		}
	}
	vector<deque<bool>> dp(M, deque<bool>(11));
	fill(dp[0].begin(), dp[0].end(), true);
	for (int i = 0; i < M - 1; ++i) {
		for (int j = 0; j < B[i].size(); ++j) {
			if (!dp[i][j]) {
				continue;
			}
			for (int k = 0; k < B[i + 1].size(); ++k) {
				if (B[i][j].second < B[i + 1][k].first || B[i + 1][k].second < B[i][j].first) {
					continue;
				}
				dp[i + 1][k] = true;
			}
		}
	}
	cout << (accumulate(dp[M - 1].begin(), dp[M - 1].end(), 0) ? "YES" : "NO") << "\n";
	return 0;
}
