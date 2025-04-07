#include <bits/stdc++.h>

using namespace std;

const int dx[4]{1, -1, 0, 0};
const int dy[4]{0, 0, 1, -1};

int N, M;
vector<deque<bool>> A;

void dfs(int x, int y) {
	A[x][y] = false;
	for (int i = 0; i < 4; ++i) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (0 <= nx && nx < N && 0 <= ny && ny < M && A[nx][ny]) {
			dfs(nx, ny);
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T{};
	cin >> T;
	while (T--) {
		int K{};
		cin >> N >> M >> K;
		A.assign(N, deque<bool>(M));
		while (K--) {
			int x{}, y{};
			cin >> x >> y;
			A[x][y] = true;
		}
		int ans{};
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < M; ++j) {
				if (A[i][j]) {
					dfs(i, j);
					++ans;
				}
			}
		}
		cout << ans << "\n";
	}
	return 0;
}
