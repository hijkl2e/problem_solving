#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int dp[300001][4][4][4][3];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	vector<int> A(N);
	for (int i = 0; i < N; ++i) {
		cin >> A[i];
	}
	vector<int> B(3);
	for (int i = N; i >= 0; --i) {
		for (B[0] = 0; B[0] < 4; ++B[0]) {
			for (B[1] = 0; B[1] < 4; ++B[1]) {
				for (B[2] = 0; B[2] < 4; ++B[2]) {
					for (int m = 0; m < 3; ++m) {
						int &val = dp[i][B[0]][B[1]][B[2]][m];
						if (B[m]) {
							val = i;
							continue;
						} else if (i == N) {
							continue;
						}
						for (int n = 0; n < 3; ++n) {
							if (B[n] == 0 || (B[n] & A[i])) {
								int x = B[n];
								B[n] = A[i];
								val = dp[i + 1][B[0]][B[1]][B[2]][m];
								B[n] = x;
								break;
							}
						}
					}
				}
			}
		}
	}
	ll ans{};
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < 3; ++j) {
			int &val = dp[i][0][0][0][j];
			if (val) {
				ans += N - val + 1;
			}
		}
		if (A[i] == 0) {
			ans += (N - i) * (i + 1LL);
		}
	}
	cout << ans << "\n";
	return 0;
}
