#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, M{};
	cin >> N >> M;
	vector<vector<int>> A(M + 1, vector<int>(N + 1));
	for (int i = 1; i <= N; ++i) {
		for (int j = 0; j <= M; ++j) {
			cin >> A[j][i];
		}
	}
	vector<vector<int>> dp(M + 1, vector<int>(N + 1));
	vector<vector<int>> par(M + 1, vector<int>(N + 1));
	for (int i = 1; i <= M; ++i) {
		for (int j = 0; j <= N; ++j) {
			for (int k = 0; k <= j; ++k) {
				if (dp[i][j] < dp[i - 1][j - k] + A[i][k]) {
					dp[i][j] = dp[i - 1][j - k] + A[i][k];
					par[i][j] = k;
				}
			}
		}
	}
	stack<int> st;
	int x = N;
	for (int i = M; i > 0; --i) {
		st.push(par[i][x]);
		x -= par[i][x];
	}
	cout << dp[M][N] << "\n";
	while (st.size()) {
		x = st.top(); st.pop();
		cout << x << (st.size() ? " " : "\n");
	}
	return 0;
}
