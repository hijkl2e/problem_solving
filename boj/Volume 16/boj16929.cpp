#include <bits/stdc++.h>

using namespace std;

const int dx[4]{1, -1, 0, 0};
const int dy[4]{0, 0, 1, -1};

int N, M;
vector<string> A;
vector<vector<int>> B;

bool dfs(int x, int y, int d) {
	B[x][y] = d;
	for (int i = 0; i < 4; ++i) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (0 <= nx && nx < N && 0 <= ny && ny < M && A[x][y] == A[nx][ny]) {
			if (B[nx][ny] == -1 ? dfs(nx, ny, d + 1) : (d - B[nx][ny] > 2)) {
				return true;
			}
		}
	}
	B[x][y] = -1;
	return false;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> N >> M;
	cin.ignore();
	A.resize(N);
	for (int i = 0; i < N; ++i) {
		getline(cin, A[i]);
	}
	B.assign(N, vector<int>(M, -1));
	bool yes{};
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			if (dfs(i, j, 0)) {
				yes = true;
				i = N;
				break;
			}
		}
	}
	cout << (yes ? "Yes" : "No") << "\n";
	return 0;
}
