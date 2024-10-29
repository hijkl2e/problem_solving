#include <bits/stdc++.h>

using namespace std;

const int dx[4]{-1, 0, 0, 1};
const int dy[4]{0, 1, -1, 0};

vector<vector<int>> B, C;
int ans;

void dfs(int x, int y) {
	C[x][y] = 1;
	int d = B[x][y];
	int nx = x + dx[d];
	int ny = y + dy[d];
	if (C[nx][ny] == 0) {
		dfs(nx, ny);
	} else if (C[nx][ny] == 1) {
		++ans;
	}
	C[x][y] = 2;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, M{};
	cin >> N >> M;
	cin.ignore();
	vector<string> A(N);
	for (int i = 0; i < N; ++i) {
		cin >> A[i];
	}
	B.assign(N, vector<int>(M));
	string news = "NEWS";
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			B[i][j] = news.find(A[i][j]);
		}
	}
	C.assign(N, vector<int>(M));
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			if (C[i][j] == 0) {
				dfs(i, j);
			}
		}
	}
	cout << ans << "\n";
	return 0;
}
