#include <bits/stdc++.h>

using namespace std;

const int dx[4]{1, 0, -1, 0};
const int dy[4]{0, 1, 0, -1};

int N, M;
vector<vector<int>> A, B;

void dfs(int x, int y, int c) {
	B[x][y] = c;
	for (int i = 0; i < 4; ++i) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (0 <= nx && nx < N && 0 <= ny && ny < M && A[nx][ny] && B[nx][ny] == -1) {
			dfs(nx, ny, c);
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> N >> M;
	A.assign(N, vector<int>(M));
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			cin >> A[i][j];
		}
	}
	B.assign(N, vector<int>(M, -1));
	int cnt{};
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			if (A[i][j] && B[i][j] == -1) {
				dfs(i, j, cnt++);
			}
		}
	}
	vector<int> C(cnt + 1);
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			if (A[i][j]) {
				++C[B[i][j]];
			}
		}
	}
	cout << cnt << "\n";
	cout << *max_element(C.begin(), C.end()) << "\n";
	return 0;
}
