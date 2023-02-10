#include <bits/stdc++.h>

using namespace std;

using ii = pair<int, int>;

int N;
vector<vector<int>> A;
vector<deque<bool>> B;

ii solve() {
	vector<vector<int>> dp1(N + 1, vector<int>(N + 1));
	vector<vector<int>> dp2(N + 1, vector<int>(N + 1));
	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= N; ++j) {
			dp1[i][j] = max(dp1[i - 1][j], dp1[i][j - 1]) + A[i][j];
			if (dp1[i - 1][j] > dp1[i][j - 1]) {
				dp2[i][j] = dp2[i - 1][j];
			} else if (dp1[i - 1][j] < dp1[i][j - 1]) {
				dp2[i][j] = dp2[i][j - 1];
			} else {
				dp2[i][j] = max(dp2[i - 1][j], dp2[i][j - 1]);
			}
			dp2[i][j] += B[i][j];
		}
	}
	return {dp1[N][N], dp2[N][N]};
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> N;
	A.assign(N + 1, vector<int>(N + 1));
	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= N; ++j) {
			cin >> A[i][j];
		}
	}
	B.assign(N + 1, deque<bool>(N + 1));
	int P{};
	cin >> P;
	while (P--) {
		int r{}, c{};
		cin >> r >> c;
		B[r][c] = true;
	}
	ii ans = solve();
	cout << ans.first << " " << ans.second << "\n";
	return 0;
}
