#include <bits/stdc++.h>

using namespace std;

const int dx[8]{-1, -1, -1, 0, 1, 1, 1, 0};
const int dy[8]{-1, 0, 1, 1, 1, 0, -1, -1};

int N, M;
vector<vector<int>> A;
vector<deque<bool>> vst;

void dfs(int x, int y) {
	vst[x][y] = true;
	for (int i = 0; i < 8; ++i) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (0 <= nx && nx < N && 0 <= ny && ny < M && A[nx][ny] && !vst[nx][ny]) {
			dfs(nx, ny);
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	while (cin >> M >> N, N) {
		A.assign(N, vector<int>(M));
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < M; ++j) {
				cin >> A[i][j];
			}
		}
		vst.assign(N, deque<bool>(M));
		int ans{};
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < M; ++j) {
				if (A[i][j] && !vst[i][j]) {
					dfs(i, j);
					++ans;
				}
			}
		}
		cout << ans << "\n";
	}
	return 0;
}
