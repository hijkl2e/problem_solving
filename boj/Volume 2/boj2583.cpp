#include <bits/stdc++.h>

using namespace std;

const int dx[4]{1, -1, 0, 0};
const int dy[4]{0, 0, 1, -1};

int N, M;
vector<vector<int>> A;

void dfs(int x, int y, int c) {
	A[x][y] = c;
	for (int i = 0; i < 4; ++i) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (0 <= nx && nx < N && 0 <= ny && ny < M && A[nx][ny] == -1) {
			dfs(nx, ny, c);
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int K{};
	cin >> M >> N >> K;
	A.assign(N, vector<int>(M, -1));
	while (K--) {
		int x1{}, y1{}, x2{}, y2{};
		cin >> x1 >> y1 >> x2 >> y2;
		for (int i = x1; i < x2; ++i) {
			for (int j = y1; j < y2; ++j) {
				A[i][j] = 0;
			}
		}
	}
	int cnt{};
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			if (A[i][j] == -1) {
				dfs(i, j, ++cnt);
			}
		}
	}
	vector<int> B(cnt + 1);
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			++B[A[i][j]];
		}
	}
	sort(B.begin() + 1, B.end());
	cout << cnt << "\n";
	for (int i = 1; i < B.size(); ++i) {
		cout << B[i] << (i == B.size() - 1 ? "\n" : " ");
	}
	return 0;
}
