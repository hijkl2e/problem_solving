#include <bits/stdc++.h>

using namespace std;

using ii = pair<int, int>;

const int INF = 1e9 + 7;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	cin.ignore();
	string A, B;
	getline(cin, A);
	getline(cin, B);
	vector<vector<int>> dp(N + 1, vector<int>(10, INF));
	vector<vector<ii>> par(N + 1, vector<ii>(10));
	dp[0][0] = 0;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < 10; ++j) {
			int x = (A[i] - '0' + j + 10) % 10;
			for (int k = 0; k < 10; ++k) {
				int y = ((x + k) % 10 - B[i] + '0' + 10) % 10;
				int &val = dp[i + 1][(j + k) % 10];
				if (val > dp[i][j] + k + y) {
					val = dp[i][j] + k + y;
					par[i + 1][(j + k) % 10] = {k, y};
				}
			}
		}
	}
	int p = min_element(dp[N].begin(), dp[N].end()) - dp[N].begin();
	cout << dp[N][p] << "\n";
	for (int i = N; i > 0; --i) {
		auto &[x, y] = par[i][p];
		if (x) {
			cout << i << " " << x << "\n";
		}
		if (y) {
			cout << i << " " << -y << "\n";
		}
		p = (p - x + 10) % 10;
	}
	return 0;
}
