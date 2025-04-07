#include <bits/stdc++.h>

using namespace std;

const int dx[8]{1, -1, 0, 0, 1, -1, 1, -1};
const int dy[8]{0, 0, 1, -1, 1, 1, -1, -1};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	map<string, int> d2i{
		{"R", 0}, {"L", 1}, {"T", 2}, {"B", 3},
		{"RT", 4}, {"LT", 5}, {"RB", 6}, {"LB", 7},
	};
	string s1, s2;
	int N{};
	cin >> s1 >> s2 >> N;
	int x1 = s1[0] - 'A';
	int y1 = s1[1] - '1';
	int x2 = s2[0] - 'A';
	int y2 = s2[1] - '1';
	while (N--) {
		cin >> s1;
		int d = d2i[s1];
		int nx = x1 + dx[d];
		int ny = y1 + dy[d];
		if (nx == -1 || nx == 8 || ny == -1 || ny == 8) {
			continue;
		}
		if (nx == x2 && ny == y2) {
			nx = x2 + dx[d];
			ny = y2 + dy[d];
			if (nx == -1 || nx == 8 || ny == -1 || ny == 8) {
				continue;
			}
			x1 = x2, y1 = y2;
			x2 = nx, y2 = ny;
		} else {
			x1 = nx, y1 = ny;
		}
	}
	char c1 = 'A' + x1;
	char c2 = 'A' + x2;
	cout << c1 << y1 + 1 << "\n" << c2 << y2 + 1 << "\n";
	return 0;
}
