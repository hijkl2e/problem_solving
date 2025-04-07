#include <bits/stdc++.h>

using namespace std;

const int dx[4]{0, -1, 0, 1};
const int dy[4]{1, 0, -1, 0};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int R{}, C{}, T{};
	cin >> R >> C >> T;
	vector<vector<int>> A(R, vector<int>(C));
	for (int i = 0; i < R; ++i) {
		for (int j = 0; j < C; ++j) {
			cin >> A[i][j];
		}
	}
	int ac{};
	for (int i = 0; i < R; ++i) {
		if (A[i][0] == -1) {
			ac = i;
			break;
		}
	}
	vector<vector<int>> B(R, vector<int>(C));
	while (T--) {
		for (int i = 0; i < R; ++i) {
			fill(B[i].begin(), B[i].end(), 0);
		}
		for (int i = 0; i < R; ++i) {
			for (int j = 0; j < C; ++j) {
				int z = A[i][j] / 5;
				for (int k = 0; k < 4; ++k) {
					int nx = i + dx[k];
					int ny = j + dy[k];
					if (0 <= nx && nx < R && 0 <= ny && ny < C && A[nx][ny] != -1) {
						B[nx][ny] += z;
						A[i][j] -= z;
					}
				}
			}
		}
		for (int i = 0; i < R; ++i) {
			for (int j = 0; j < C; ++j) {
				A[i][j] += B[i][j];
			}
		}
		for (int k = 0; k < 2; ++k) {
			int x = ac + k, y = 1;
			int d{}, p{};
			while (x != ac + k || y != 0) {
				swap(A[x][y], p);
				x += dx[d];
				y += dy[d];
				if (x == -1 || x == R || y == -1 || y == C) {
					x -= dx[d];
					y -= dy[d];
					d = (d + (k ? 3 : 1)) % 4;
					x += dx[d];
					y += dy[d];
				}
			}
		}
	}
	int ans = 2;
	for (int i = 0; i < R; ++i) {
		ans += accumulate(A[i].begin(), A[i].end(), 0);
	}
	cout << ans << "\n";
	return 0;
}
