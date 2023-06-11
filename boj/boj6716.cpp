#include <bits/stdc++.h>

using namespace std;

using ii = pair<int, int>;

const int INF = 1e9 + 7;

int N;
vector<ii> A;
vector<vector<int>> dp;

int dist(ii &a, ii &b) {
	return abs(a.first - b.first) + abs(a.second - b.second);
}

int solve(int u, int x) {
	if (dp[u][x] != INF) {
		return dp[u][x];
	} else if (x == 0) {
		return dp[u][x] = dist(A[u], A[N - 1]);
	}
	int &val = dp[u][x];
	for (int i = 0; i < N - 1; ++i) {
		if (x & (1 << i)) {
			val = min(val, dist(A[u], A[i]) + solve(i, x & ~(1 << i)));
		}
	}
	return val;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T{};
	cin >> T;
	while (T--) {
		int x{}, y{};
		cin >> x >> y >> x >> y >> N;
		A.resize(++N);
		A[N - 1] = {x, y};
		for (int i = 0; i < N - 1; ++i) {
			cin >> x >> y;
			A[i] = {x, y};
		}
		dp.assign(N, vector<int>(1 << (N - 1), INF));
		cout << "The shortest path has length " << solve(N - 1, (1 << (N - 1)) - 1) << "\n";
	}
	return 0;
}
