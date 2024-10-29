#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, M{};
	cin >> N >> M;
	if (N > M) {
		swap(N, M);
	}
	vector<int> A(1 << (N - 1));
	for (int i = 0; i < (1 << N); ++i) {
		int x{};
		for (int j = 0; j < N - 1; ++j) {
			if ((i >> j) & (i >> (j + 1)) & 1) {
				x |= 1 << j;
			}
		}
		++A[x];
	}
	vector<int> B;
	for (int i = 0; i < A.size(); ++i) {
		if (A[i]) {
			B.push_back(i);
		}
	}
	vector<vector<int>> C(B.size());
	for (int i = 0; i < B.size(); ++i) {
		for (int j = 0; j < B.size(); ++j) {
			if ((B[i] & B[j]) == 0) {
				C[i].push_back(j);
			}
		}
	}
	for (int i = 0; i < B.size(); ++i) {
		B[i] = A[B[i]];
	}
	vector<vector<int>> dp(2, vector<int>(C.size()));
	dp[0][0] = 1;
	while (M--) {
		fill(dp[1].begin(), dp[1].end(), 0);
		for (int u = 0; u < C.size(); ++u) {
			for (int v : C[u]) {
				dp[1][v] += B[v] * dp[0][u];
			}
		}
		swap(dp[0], dp[1]);
	}
	int ans = accumulate(dp[0].begin(), dp[0].end(), 0);
	cout << ans << "\n";
	return 0;
}
