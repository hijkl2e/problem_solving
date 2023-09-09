#include <bits/stdc++.h>

using namespace std;

const int dx[4]{1, 0, -1, 0};
const int dy[4]{0, -1, 0, 1};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	cin.ignore();
	string S;
	getline(cin, S);
	vector<string> A(101, string(101, '#'));
	int x{}, y{}, minx{}, maxx{}, miny{}, maxy{}, d{};
	x = y = minx = maxx = miny = maxy = 50;
	A[x][y] = '.';
	for (char c : S) {
		if (c == 'L') {
			d = (d + 3) % 4;
		} else if (c == 'R') {
			d = (d + 1) % 4;
		} else {
			x += dx[d];
			y += dy[d];
			A[x][y] = '.';
			minx = min(minx, x);
			maxx = max(maxx, x);
			miny = min(miny, y);
			maxy = max(maxy, y);
		}
	}
	for (int i = minx; i <= maxx; ++i) {
		for (int j = miny; j <= maxy; ++j) {
			cout << A[i][j];
		}
		cout << "\n";
	}
	return 0;
}
