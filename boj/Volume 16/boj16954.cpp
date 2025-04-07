#include <bits/stdc++.h>

using namespace std;

using iii = tuple<int, int, int>;

const int dx[8]{-1, -1, -1, 0, 1, 1, 1, 0};
const int dy[8]{-1, 0, 1, 1, 1, 0, -1, -1};

string A[9][8];
bool vst[9][8][8];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	for (int i = 0; i < 8; ++i) {
		getline(cin, A[0][i]);
	}
	for (int i = 1; i < 9; ++i) {
		A[i][0] = string(8, '.');
		for (int j = 1; j < 8; ++j) {
			A[i][j] = A[i - 1][j - 1];
		}
	}
	queue<iii> q;
	vst[0][7][0] = true;
	q.push({0, 7, 0});
	while (q.size()) {
		auto [z, x, y] = q.front(); q.pop();
		for (int i = 0; i < 8; ++i) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			int nz = z + (z < 8);
			if (0 <= nx && nx < 8 && 0 <= ny && ny < 8 && A[z][nx][ny] == '.'
					&& A[nz][nx][ny] == '.' && !vst[nz][nx][ny]) {
				vst[nz][nx][ny] = true;
				q.push({nz, nx, ny});
			}
		}
		if (z < 8 && A[z + 1][x][y] == '.') {
			vst[z + 1][x][y] = true;
			q.push({z + 1, x, y});
		}
	}
	cout << vst[8][0][7] << "\n";
	return 0;
}
