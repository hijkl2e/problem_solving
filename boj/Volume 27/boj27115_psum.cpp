#include <bits/stdc++.h>

using namespace std;

const int dx[6]{-1, -1, 1, 1, 1, 0};
const int dy[6]{-1, 1, -1, 1, 0, 1};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, M{}, K{};
	cin >> N >> M >> K;
	vector<vector<int>> A(N + M, vector<int>(N + M));
	while (K--) {
		int r{}, c{}, d{};
		cin >> r >> c >> d;
		--r, --c;
		int x = r + c;
		int y = r - c + M - 1;
		for (int i = 0; i < 4; ++i) {
			int nx = x + dx[i] * d + i / 2;
			int ny = y + dy[i] * d + i % 2;
			nx = min(nx, N + M - 1);
			ny = min(ny, N + M - 1);
			nx = max(nx, 0);
			ny = max(ny, 0);
			A[nx][ny] += i % 3 == 0 ? 1 : -1;
		}
	}
	for (int i = 0; i < N + M - 1; ++i) {
		for (int j = 0; j < N + M - 1; ++j) {
			for (int k = 3; k < 6; ++k) {
				int nx = i + dx[k];
				int ny = j + dy[k];
				A[nx][ny] += (k == 3 ? -1 : 1) * A[i][j];
			}
		}
	}
	int ans{};
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			int x = i + j;
			int y = i - j + M - 1;
			if (A[x][y]) {
				++ans;
			}
		}
	}
	cout << ans << "\n";
	return 0;
}
