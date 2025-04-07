#include <bits/stdc++.h>

using namespace std;

const int dx[4]{-1, 0, 1, 0};
const int dy[4]{0, 1, 0, -1};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, M{};
	cin >> N >> M;
	int r{}, c{}, d{};
	cin >> r >> c >> d;
	vector<vector<int>> A(N, vector<int>(M));
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			cin >> A[i][j];
		}
	}
	int ans{};
	while (true) {
		if (A[r][c] == 0) {
			A[r][c] = 2;
			++ans;
		}
		bool flag{};
		for (int i = 0; i < 4; ++i) {
			d = (d + 3) % 4;
			int nx = r + dx[d];
			int ny = c + dy[d];
			if (A[nx][ny] == 0) {
				r = nx, c = ny;
				flag = true;
				break;
			}
		}
		if (flag) {
			continue;
		}
		r -= dx[d];
		c -= dy[d];
		if (A[r][c] == 1) {
			break;
		}
	}
	cout << ans << "\n";
	return 0;
}
