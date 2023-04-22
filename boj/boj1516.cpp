#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	vector<int> A(N + 1);
	vector<vector<int>> G(N + 1);
	for (int i = 1; i <= N; ++i) {
		cin >> A[i];
		int x{};
		while (cin >> x, x != -1) {
			G[x].push_back(i);
		}
	}
	vector<int> ind(N + 1);
	for (int i = 1; i <= N; ++i) {
		for (int x : G[i]) {
			++ind[x];
		}
	}
	queue<int> q;
	for (int i = 1; i <= N; ++i) {
		if (ind[i] == 0) {
			q.push(i);
		}
	}
	vector<int> dp(N + 1);
	while (q.size()) {
		int x = q.front(); q.pop();
		dp[x] += A[x];
		for (int y : G[x]) {
			dp[y] = max(dp[y], dp[x]);
			if (--ind[y] == 0) {
				q.push(y);
			}
		}
	}
	for (int i = 1; i <= N; ++i) {
		cout << dp[i] << "\n";
	}
	return 0;
}
