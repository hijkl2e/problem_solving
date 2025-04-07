#include <bits/stdc++.h>

using namespace std;

using ii = pair<int, int>;

const int INF = 1e9 + 7;

vector<vector<int>> D(2, vector<int>(500001, -1));
queue<ii> q;

void solve(int x, int t) {
	int y = t % 2;
	if (x < 0 || x >= D[y].size()) {
		return;
	}
	if (D[y][x] == -1) {
		D[y][x] = t;
		q.push({t, x});
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, K{};
	cin >> N >> K;
	D[0][N] = 0;
	q.push({0, N});
	while (q.size()) {
		auto [t, x] = q.front(); q.pop();
		solve(x - 1, t + 1);
		solve(x + 1, t + 1);
		solve(2 * x, t + 1);
	}
	int ans = INF;
	for (int i = 0; K < D[i % 2].size(); K += ++i) {
		if (D[i % 2][K] <= i) {
			ans = min(ans, i);
		}
	}
	cout << (ans == INF ? -1 : ans) << "\n";
	return 0;
}
