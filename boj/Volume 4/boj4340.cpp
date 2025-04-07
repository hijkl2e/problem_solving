#include <bits/stdc++.h>

using namespace std;

const int dx[4]{1, 0, -1, 0};
const int dy[4]{0, 1, 0, -1};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	map<char, char> c2c{
		{'R', 'P'}, {'P', 'S'}, {'S', 'R'}
	};
	int T{};
	cin >> T;
	for (int tc = 0; tc < T; ++tc) {
		int R{}, C{}, N{};
		cin >> R >> C >> N;
		cin.ignore();
		vector<string> grid(R);
		for (int i = 0; i < R; ++i) {
			getline(cin, grid[i]);
		}
		while (N--) {
			vector<string> ngrid(grid.begin(), grid.end());
			for (int i = 0; i < R; ++i) {
				for (int j = 0; j < C; ++j) {
					char c = c2c[grid[i][j]];
					for (int k = 0; k < 4; ++k) {
						int nx = i + dx[k];
						int ny = j + dy[k];
						if (0 <= nx && nx < R && 0 <= ny && ny < C && grid[nx][ny] == c) {
							ngrid[i][j] = c;
							break;
						}
					}
				}
			}
			grid = ngrid;
		}
		if (tc) {
			cout << "\n";
		}
		for (auto &s : grid) {
			cout << s << "\n";
		}
	}
	return 0;
}
