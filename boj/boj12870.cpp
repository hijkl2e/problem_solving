#include <bits/stdc++.h>

using namespace std;

const int INF = 0x3f3f3f3f;

int dp[21][101][101];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	vector<int> A(N);
	for (int i = 0; i < N; ++i) {
		cin >> A[i];
	}
	int lo = 0, hi = 101;
	while (lo + 1 < hi) {
		int mid = (lo + hi) / 2;
		memset(dp, 0x3f, sizeof dp);
		dp[0][0][0] = 0;
		for (int i = 0; i < N; ++i) {
			int x = A[i] + 9;
			for (int j = 0; j <= mid && x > 0; ++j) {
				int y = (x -= 9) + 3;
				for (int k = 0; j + k <= mid && (k == 0 || y > 0); ++k) {
					int z = max(y -= 3, 0);
					if (j + k + z > mid) {
						continue;
					}
					for (int l = 0; j + l <= mid; ++l) {
						for (int m = 0; k + m <= mid; ++m) {
							if (dp[i][l][m] == INF) {
								continue;
							}
							int &val = dp[i + 1][j + l][k + m];
							val = min(val, dp[i][l][m] + z);
						}
					}
				}
			}
		}
		int minv = INF;
		for (int j = 0; j <= mid; ++j) {
			for (int k = 0; k <= mid; ++k) {
				minv = min(minv, dp[N][j][k]);
			}
		}
		if (minv > mid) {
			lo = mid;
		} else {
			hi = mid;
		}
	}
	cout << hi << "\n";
	return 0;
}
