#include <bits/stdc++.h>

using namespace std;

const int dx[6]{1, 0, -1, -1, 0, 1};
const int dy[6]{0, 1, 1, 0, -1, -1};

int N;
vector<string> A;
vector<vector<int>> B;

bool dfs(int x, int y, int c, int d) {
	B[x][y] = c;
	for (int i = 0; i < 6; ++i) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (0 <= nx && nx < N && 0 <= ny && ny < N && A[nx][ny] == 'X'
				&& (B[nx][ny] == -1 ? !dfs(nx, ny, d, c) : (B[x][y] == B[nx][ny]))) {
			return false;
		}
	}
	return true;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> N;
	cin.ignore();
	A.resize(N);
	for (int i = 0; i < N; ++i) {
		getline(cin, A[i]);
	}
	int ans{};
	for (int k = 0; k < 2; ++k) {
		B.assign(N, vector<int>(N, -1));
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < N; ++j) {
				if (A[i][j] == '-') {
					continue;
				}
				ans = max(ans, 1);
				if (B[i][j] == -1 && !dfs(i, j, k, 0)) {
					ans = max(ans, k + 2);
				}
			}
		}
	}
	cout << ans << "\n";
	return 0;
}
