#include <bits/stdc++.h>

using namespace std;

const int dx[4]{1, -1, 0, 0};
const int dy[4]{0, 0, 1, -1};

int N;
vector<vector<int>> A;
vector<deque<bool>> vst;

void dfs(int x, int y, int z) {
	vst[x][y] = true;
	for (int i = 0; i < 4; ++i) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (0 <= nx && nx < N && 0 <= ny && ny < N && A[nx][ny] > z && !vst[nx][ny]) {
			dfs(nx, ny, z);
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> N;
	A.assign(N, vector<int>(N));
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			cin >> A[i][j];
		}
	}
	vst.assign(N, deque<bool>(N));
	int ans{};
	for (int k = 0; k < 100; ++k) {
		for (int i = 0; i < N; ++i) {
			fill(vst[i].begin(), vst[i].end(), false);
		}
		int cnt{};
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < N; ++j) {
				if (A[i][j] > k && !vst[i][j]) {
					dfs(i, j, k);
					++cnt;
				}
			}
		}
		ans = max(ans, cnt);
	}
	cout << ans << "\n";
	return 0;
}
