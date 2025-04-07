#include <bits/stdc++.h>

using namespace std;

const int dx[4]{0, 1, 0, -1};
const int dy[4]{1, 0, -1, 0};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	vector<string> grid(8);
	for (int i = 0; i < 8; ++i) {
		getline(cin, grid[i]);
	}
	string S;
	getline(cin, S);
	int x = 7, y = 0, dir = 0;
	bool yes = true;
	for (char c : S) {
		if (c == 'F') {
			int nx = x + dx[dir];
			int ny = y + dy[dir];
			if (nx == -1 || nx == 8 || ny == -1 || ny == 8
					|| grid[nx][ny] == 'C' || grid[nx][ny] == 'I') {
				yes = false;
				break;
			}
			x = nx;
			y = ny;
		} else if (c == 'R') {
			dir = (dir + 1) % 4;
		} else if (c == 'L') {
			dir = (dir + 3) % 4;
		} else {
			int nx = x + dx[dir];
			int ny = y + dy[dir];
			if (nx == -1 || nx == 8 || ny == -1 || ny == 8 || grid[nx][ny] != 'I') {
				yes = false;
				break;
			}
			grid[nx][ny] = '.';
		}
	}
	yes &= grid[x][y] == 'D';
	cout << (yes ? "Diamond!" : "Bug!") << "\n";
	return 0;
}
