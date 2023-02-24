#include <bits/stdc++.h>

using namespace std;

const int dx[4]{1, -1, 0, 0};
const int dy[4]{0, 0, 1, -1};

int N, M, ans;
vector<vector<int>> A;

void dfs(int x, int y, int z, int w, int s) {
	if (z == 4) {
		ans = max(ans, w);
		return;
	}
	for (int i = 0; i < 4; ++i) {
		if (i == s) {
			continue;
		}
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (A[nx][ny]) {
			dfs(nx, ny, z + 1, w + A[nx][ny], i ^ 1);
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> N >> M;
	A.assign(N + 2, vector<int>(M + 2));
	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= M; ++j) {
			cin >> A[i][j];
		}
	}
	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= M; ++j) {
			dfs(i, j, 1, A[i][j], -1);
		}
	}
	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= M; ++j) {
			int w = A[i][j], minv = 1e9;
			for (int k = 0; k < 4; ++k) {
				int nx = i + dx[k];
				int ny = j + dy[k];
				w += A[nx][ny];
				minv = min(minv, A[nx][ny]);
			}
			ans = max(ans, w - minv);
		}
	}
	cout << ans << "\n";
	return 0;
}
