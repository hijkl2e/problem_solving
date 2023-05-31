#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9 + 7;

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
	swap(N, M);
	vector<string> B(N, string(M, '.'));
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			B[i][j] = A[j][i];
		}
	}
	vector<int> C;
	for (int i = 0; i < (1 << M); ++i) {
		bool yes = true;
		for (int j = 0; j < M; ++j) {
			if (i & (1 << j)) {
				if (i & (1 << (j + 1))) {
					++j;
				} else {
					yes = false;
					break;
				}
			}
		}
		if (yes) {
			C.push_back(i);
		}
	}
	vector<vector<int>> dp(N + 1, vector<int>(1 << M, -INF));
	dp[0][0] = 0;
	for (int i = 0; i < N; ++i) {
		int x{};
		for (int j = 0; j < M; ++j) {
			if (B[i][j] == '1') {
				x |= 1 << j;
			}
		}
		for (int y : C) {
			if (x & y) {
				continue;
			}
			for (int z : C) {
				if ((x | y) & z) {
					continue;
				}
				dp[i + 1][z] = max(dp[i + 1][z], dp[i][y] + 6 * __builtin_popcount(z));
			}
		}
	}
	int ans = dp[N][0] + N * M;
	cout << ans << "\n";
	return 0;
}
