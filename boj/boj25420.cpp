#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9 + 7;

int N, K;
vector<vector<int>> dp1, dp2;
deque<bool> A;

bool solve(int t, int x) {
	if (dp1[t][x] != -1) {
		return dp1[t][x];
	}
	int cnt1 = INF, cnt2 = -1;
	for (int i = 1; i <= K && x + i <= N; ++i) {
		if (A[x + i]) {
			continue;
		}
		if (solve(t ^ 1, x + i) == t) {
			cnt1 = min(cnt1, dp2[t ^ 1][x + i]);
		} else {
			cnt2 = max(cnt2, dp2[t ^ 1][x + i]);
		}
	}
	dp2[t][x] += cnt1 == INF ? cnt2 : cnt1;
	return dp1[t][x] = (t ^ (cnt1 == INF));
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> N >> K;
	A.resize(N + 1);
	int x{};
	while (cin >> x) {
		A[x] = true;
	}
	dp1.assign(2, vector<int>(N + 1, -1));
	dp2.assign(2, vector<int>(N + 1, 1));
	solve(1, 0);
	cout << dp2[1][0] << "\n";
	return 0;
}
