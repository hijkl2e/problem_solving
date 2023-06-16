#include <bits/stdc++.h>

using namespace std;

bool dp[1 << 15][15][10];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	cin.ignore();
	vector<string> A(N);
	for (int i = 0; i < N; ++i) {
		getline(cin, A[i]);
	}
	dp[1][0][0] = true;
	int ans{};
	for (int i = 1; i < (1 << N); ++i) {
		for (int j = 0; j < N; ++j) {
			for (int k = 0; k < 10; ++k) {
				if (!dp[i][j][k]) {
					continue;
				}
				ans = max<int>(ans, __builtin_popcount(i));
				for (int l = 0; l < N; ++l) {
					if ((i & (1 << l)) == 0 && A[j][l] - '0' >= k) {
						dp[i | (1 << l)][l][A[j][l] - '0'] = true;
					}
				}
			}
		}
	}
	cout << ans << "\n";
	return 0;
}
