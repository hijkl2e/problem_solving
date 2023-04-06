#include <bits/stdc++.h>

using namespace std;

const int dx[4]{1, -1, 0, 0};
const int dy[4]{0, 0, 1, -1};

int N;
vector<vector<int>> A;

void dfs(int x, int y, int c) {
	A[x][y] = c;
	for (int i = 0; i < 4; ++i) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (0 <= nx && nx < N && 0 <= ny && ny < N && A[nx][ny] == -1) {
			dfs(nx, ny, c);
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int M{}, K{};
	cin >> N >> M >> K;
	A.assign(N, vector<int>(N));
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			cin >> A[i][j];
			--A[i][j];
		}
	}
	int cnt{};
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			if (A[i][j] == -1) {
				dfs(i, j, ++cnt);
			}
		}
	}
	vector<int> B(cnt + 1);
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			++B[A[i][j]];
		}
	}
	for (int i = 1; i < B.size(); ++i) {
		M -= (B[i] - 1) / K + 1;
	}
	if (cnt && M >= 0) {
		cout << "POSSIBLE\n" << M << "\n";
	} else {
		cout << "IMPOSSIBLE\n";
	}
	return 0;
}
