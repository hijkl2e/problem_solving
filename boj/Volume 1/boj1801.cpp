#include <bits/stdc++.h>

using namespace std;

int dp[2][41][41][71];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	vector<int> A(N);
	for (int i = 0; i < N; ++i) {
		cin >> A[i];
	}
	memset(dp, -1, sizeof dp);
	dp[1][0][0][0] = 0;
	vector<int> B(3);
	for (int i = 0; i < N; ++i) {
		memcpy(dp[0], dp[1], sizeof dp[1]);
		for (B[0] = 0; B[0] < 41; ++B[0]) {
			for (B[1] = 0; B[1] < 41; ++B[1]) {
				for (B[2] = 0; B[2] < 71; ++B[2]) {
					int &x = dp[0][B[0]][B[1]][B[2]];
					if (x == -1) {
						continue;
					}
					for (int j = 0; j < 3; ++j) {
						if (B[j] + A[i] > (j == 2 ? 70 : 40)) {
							continue;
						}
						B[j] += A[i];
						int &val = dp[1][B[0]][B[1]][B[2]];
						val = max(val, x);
						B[j] -= A[i];
					}
					int &val = dp[1][B[0]][B[1]][abs(B[2] - A[i])];
					val = max(val, x + min(A[i], B[2]));
				}
			}
		}
	}
	int ans{};
	for (int i = 1; i < 41; ++i) {
		ans = max(ans, i * dp[1][i][i][0]);
	}
	cout << (ans ? ans : -1) << "\n";
	return 0;
}
