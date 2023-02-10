#include <bits/stdc++.h>

using namespace std;

using ii = pair<int, int>;

const int INF = 1e9 + 7;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int A{}, B{}, C{}, K{};
	cin >> A >> B >> C >> K;
	vector<ii> D{
		{4 * A, 4}, {4 * B, 4}, {2 * C, 2},
		{A + B, 2}, {2 * A + C, 3}, {2 * B + C, 3}
	};
	vector<int> dp(K + 1, INF);
	dp[K] = 0;
	for (int i = K; i > 0; --i) {
		for (auto &p : D) {
			if (i - p.first < 0) {
				continue;
			}
			int &val = dp[i - p.first];
			val = min(val, dp[i] + p.second);
		}
	}
	cout << (dp[0] == INF ? -1 : dp[0]) << "\n";
	return 0;
}
