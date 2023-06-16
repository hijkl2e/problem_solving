#include <bits/stdc++.h>

using namespace std;

using ll = long long;

ll dp[1 << 13][13][2][14];

bool compare(string &L, int l, string &R, int r, int cnt) {
	for (int i = 0; i < cnt; ++i) {
		if (L[l + cnt - i - 1] != R[r + i]) {
			return false;
		}
	}
	return true;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	vector<string> A(N);
	for (int i = 0; i < N; ++i) {
		cin >> A[i];
	}
	ll ans{};
	for (int n = 0; n < 2; ++n) {
		memset(dp, 0, sizeof dp);
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < A[i].size(); ++j) {
				int l = A[i].size() - j - n;
				int r = j;
				int minl = min(l, r);
				if (compare(A[i], l - minl, A[i], l + n, minl)) {
					dp[1 << i][i][l < r][abs(l - r)] = 1;
				}
			}
		}
		for (int i = 1; i < (1 << N); ++i) {
			for (int j = 0; j < N; ++j) {
				for (int k = 0; k < 2; ++k) {
					for (int l = 0; l <= A[j].size(); ++l) {
						if (dp[i][j][k][l] == 0) {
							continue;
						}
						for (int m = 0; m < N; ++m) {
							if (i & (1 << m)) {
								continue;
							}
							int minl = min<int>(l, A[m].size());
							int maxl = max<int>(l, A[m].size());
							if (k ? compare(A[j], A[j].size() - l, A[m], A[m].size() - minl, minl)
									: compare(A[j], l - minl, A[m], 0, minl)) {
								dp[i | (1 << m)][l == minl ? m : j][k ^ (l == minl)][maxl - minl]
										+= dp[i][j][k][l];
							}
						}
					}
				}
			}
		}
		for (int i = 1; i < (1 << N); ++i) {
			for (int j = 0; j < N; ++j) {
				ans += dp[i][j][0][0] + dp[i][j][1][0];
			}
		}
	}
	cout << ans << "\n";
	return 0;
}
