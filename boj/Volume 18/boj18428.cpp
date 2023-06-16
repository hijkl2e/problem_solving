#include <bits/stdc++.h>

using namespace std;

const int dx[4]{1, -1, 0, 0};
const int dy[4]{0, 0, 1, -1};

int N;
vector<vector<char>> A;

bool solve(int n, int x, int y) {
	if (n == 3) {
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < N; ++j) {
				if (A[i][j] != 'T') {
					continue;
				}
				for (int k = 0; k < 4; ++k) {
					int nx = i + dx[k];
					int ny = j + dy[k];
					while (0 <= nx && nx < N && 0 <= ny && ny < N && A[nx][ny] == 'X') {
						nx += dx[k];
						ny += dy[k];
					}
					if (0 <= nx && nx < N && 0 <= ny && ny < N && A[nx][ny] == 'S') {
						return false;
					}
				}
			}
		}
		return true;
	}
	for (int i = x; i < N; ++i) {
		for (int j = i == x ? y : 0; j < N; ++j) {
			if (A[i][j] == 'X') {
				A[i][j] = 'Z';
				if (solve(n + 1, i, j + 1)) {
					return true;
				}
				A[i][j] = 'X';
			}
		}
	}
	return false;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> N;
	A.assign(N, vector<char>(N));
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			cin >> A[i][j];
		}
	}
	cout << (solve(0, 0, 0) ? "YES" : "NO") << "\n";
	return 0;
}
