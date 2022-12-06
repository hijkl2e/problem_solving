#include <bits/stdc++.h>

using namespace std;

const int dx[4]{-1, 0, 1, 0};
const int dy[4]{0, 1, 0, -1};

int N, M, ans;
vector<vector<int>> W;
vector<deque<bool>> vst;

void solve(int x, int y, int p, int d, int val) {
	ans = max(ans, val);
	if (p == 0) {
		return;
	}
	int nx = x + dx[d];
	int ny = y + dy[d];
	if (0 <= nx && nx < N && 0 <= ny && ny < M && !vst[nx][ny]) {
		vst[nx][ny] = true;
		val += W[nx][ny];
		solve(nx, ny, p - 1, d, val);
		if (p > 1) {
			solve(nx, ny, p - 2, (d + 1) % 4, val);
			solve(nx, ny, p - 2, (d + 3) % 4, val);
		}
		vst[nx][ny] = false;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> N >> M;
	W.assign(N, vector<int>(M));
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			cin >> W[i][j];
		}
	}
	int x{}, y{}, p{};
	cin >> x >> y >> p;
	vst.assign(N, deque<bool>(M));
	vst[x][y] = true;
	for (int i = 0; i < 4; ++i) {
		solve(x, y, p, i, W[x][y]);
	}
	cout << ans << "\n";
	return 0;
}
