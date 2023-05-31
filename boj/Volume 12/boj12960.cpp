#include <bits/stdc++.h>

using namespace std;

using iii = tuple<int, int, int>;

const int INF = 1e9 + 7;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	vector<vector<iii>> v1{
		{}, {{0, 0, 0}}, {{3, 1, 1}, {2, 3, 1}}, {{6, 4, 1}, {2, 6, 1}},
		{{12, 4, 1}, {8, 12, 1}, {15, 5, 2}, {11, 13, 2}, {14, 7, 2}, {10, 15, 2}}
	};
	vector<vector<iii>> v2{
		{}, {{0, 0, 0}}, {{3, 2, 1}, {1, 3, 1}}, {{6, 2, 1}, {4, 6, 1}},
		{{12, 8, 1}, {4, 12, 1}, {15, 10, 2}, {7, 14, 2}, {13, 11, 2}, {5, 15, 2}}
	};
	int R{}, C{};
	cin >> R >> C;
	cin.ignore();
	vector<string> A(R);
	for (int i = 0; i < R; ++i) {
		getline(cin, A[i]);
	}
	swap(R, C);
	vector<string> B(R, string(C, '.'));
	for (int i = 0; i < R; ++i) {
		for (int j = 0; j < C; ++j) {
			B[i][j] = A[j][i];
		}
	}
	vector<vector<int>> dp(R + 1, vector<int>(1 << C, -INF));
	dp[0][0] = 0;
	for (int i = 0; i < R; ++i) {
		auto &v = i % 2 ? v2 : v1;
		int x{};
		for (int j = 0; j < C; ++j) {
			if (B[i][j] == 'X') {
				x |= 1 << j;
			}
		}
		for (int j = 0; j < (1 << C); ++j) {
			if (x & j) {
				continue;
			}
			for (int k = C; k > 0; --k) {
				for (auto &[a, b, c] : v[k]) {
					if ((x | j) & a) {
						continue;
					}
					dp[i + 1][b] = max(dp[i + 1][b], dp[i][j] + c);
				}
			}
		}
	}
	cout << dp[R][0] << "\n";
	return 0;
}
