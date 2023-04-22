#include <bits/stdc++.h>

using namespace std;

using ii = pair<int, int>;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	vector<vector<int>> D(1001, vector<int>(501, -1));
	queue<ii> q;
	D[1][0] = 0;
	q.push({1, 0});
	while (q.size()) {
		auto [x, y] = q.front(); q.pop();
		if (x < 501 && D[x][x] == -1) {
			D[x][x] = D[x][y] + 1;
			q.push({x, x});
		}
		if (x + y < 1001 && D[x + y][y] == -1) {
			D[x + y][y] = D[x][y] + 1;
			q.push({x + y, y});
		}
		if (x && D[x - 1][y] == -1) {
			D[x - 1][y] = D[x][y] + 1;
			q.push({x - 1, y});
		}
	}
	int ans = *min_element(D[N].begin() + 1, D[N].end());
	cout << ans << "\n";
	return 0;
}
