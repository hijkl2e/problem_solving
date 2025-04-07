#include <bits/stdc++.h>

using namespace std;

int A[1005][1005][2];
int B[1005][1005][2];
int dp1[1005][1005];
int dp2[1005][1005];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	memset(dp1, -1, sizeof dp1);
	dp1[1][1] = 0;
	for (int i = 0; i < N; ++i) {
		int a{}, b{}, c{};
		cin >> a >> b >> c;
		if (a == 1 || b == 1) {
			dp1[1][1] += c;
			++dp2[1][1];
			continue;
		}
		for (int j = 1; j < b; ++j) {
			A[a][j][0] += c;
			++B[a][j][0];
		}
		for (int j = 1; j < a; ++j) {
			A[j][b][1] += c;
			++B[j][b][1];
		}
	}
	for (int i = 1; i < 1001; ++i) {
		for (int j = 1; j < 1001; ++j) {
			if (dp1[i][j] <= 0) {
				continue;
			}
			dp1[i + 1][j] = dp1[i][j] + A[i + 1][j][0] - 1;
			dp2[i + 1][j] = dp2[i][j] + B[i + 1][j][0];
			dp1[i][j + 1] = dp1[i][j] + A[i][j + 1][1] - 1;
			dp2[i][j + 1] = dp2[i][j] + B[i][j + 1][1];
		}
	}
	int ans{};
	for (int i = 1; i < 1001; ++i) {
		ans = max(ans, *max_element(dp2[i], dp2[i + 1]));
	}
	cout << ans << "\n";
	return 0;
}
