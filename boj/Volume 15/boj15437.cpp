#include <bits/stdc++.h>

using namespace std;

using ii = pair<int, int>;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int R{}, C{};
	cin >> R >> C;
	vector<string> grid(R);
	for (int i = 0; i < R; ++i) {
		cin >> grid[i];
	}
	ii now = {0, 0};
	int ans{};
	while (true) {
		auto &[x, y] = now;
		if (0 <= x && x < R && 0 <= y && y < C) {
			int nx = x, ny = y;
			if (grid[x][y] == 'N') {
				nx = x - 1;
			} else if (grid[x][y] == 'S') {
				nx = x + 1;
			} else if (grid[x][y] == 'W') {
				ny = y - 1;
			} else if (grid[x][y] == 'E') {
				ny = y + 1;
			} else if (grid[x][y] == 'T') {
				cout << ans << "\n";
				break;
			} else {
				cout << "Lost\n";
				break;
			}
			grid[x][y] = 'X';
			now = {nx, ny};
			++ans;
		} else {
			cout << "Out\n";
			break;
		}
	}
	return 0;
}
