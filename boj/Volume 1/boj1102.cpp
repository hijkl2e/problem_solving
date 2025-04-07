#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9 + 7;

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
	cin.ignore();
	string S;
	getline(cin, S);
	int P{}, x{};
	cin >> P;
	for (int i = 0; i < N; ++i) {
		if (S[i] == 'Y') {
			x |= 1 << i;
		}
	}
	vector<int> dp(1 << N, INF);
	dp[x] = 0;
	vector<int> B(N);
	for (int i = x; i < (1 << N); ++i) {
		if (dp[i] == INF) {
			continue;
		}
		fill(B.begin(), B.end(), INF);
		for (int j = 0; j < N; ++j) {
			if ((i & (1 << j)) == 0) {
				continue;
			}
			for (int k = 0; k < N; ++k) {
				B[k] = min(B[k], A[j][k]);
			}
		}
		for (int j = 0; j < N; ++j) {
			if (i & (1 << j)) {
				continue;
			}
			x = i | (1 << j);
			dp[x] = min(dp[x], dp[i] + B[j]);
		}
	}
	int ans = INF;
	for (int i = 0; i < (1 << N); ++i) {
		if (__builtin_popcount(i) >= P) {
			ans = min(ans, dp[i]);
		}
	}
	cout << (ans == INF ? -1 : ans) << "\n";
	return 0;
}
