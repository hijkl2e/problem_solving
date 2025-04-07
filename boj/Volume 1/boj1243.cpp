#include <bits/stdc++.h>

using namespace std;

int dp[31][51][2][16];

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
	int N{}, L{};
	cin >> N >> L;
	vector<string> A(N);
	for (int i = 0; i < N; ++i) {
		cin >> A[i];
	}
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < A[i].size(); ++j) {
			int l = A[i].size() - j - L % 2;
			int r = j;
			int minl = min(l, r);
			if (max(l, r) <= L / 2 && compare(A[i], l - minl, A[i], l + L % 2, minl)) {
				dp[A[i].size()][i][l < r][abs(l - r)] = 1;
			}
		}
	}
	for (int i = 1; i < L; ++i) {
		for (int j = 0; j < N; ++j) {
			for (int k = 0; k < 2; ++k) {
				for (int l = 0; l <= A[j].size(); ++l) {
					if (dp[i][j][k][l] == 0) {
						continue;
					}
					for (int m = 0; m < N; ++m) {
						int minl = min<int>(l, A[m].size());
						int maxl = max<int>(l, A[m].size());
						if (i + A[m].size() <= L && (k ?
								compare(A[j], A[j].size() - l, A[m], A[m].size() - minl, minl)
								: compare(A[j], l - minl, A[m], 0, minl))) {
							dp[i + A[m].size()][l == minl ? m : j][k ^ (l == minl)][maxl - minl]
									+= dp[i][j][k][l];
						}
					}
				}
			}
		}
	}
	int ans{};
	for (int i = 0; i < N; ++i) {
		ans += dp[L][i][0][0] + dp[L][i][1][0];
	}
	cout << ans << "\n";
	return 0;
}
