#include <bits/stdc++.h>

using namespace std;

const int dx[4]{-1, 1, 0, 0};
const int dy[4]{0, 0, -1, 1};

int A[21][21];
int B[401];
int C[401][4][4];
int D[21][21];
int E[21][21];
int x[401];
int y[401];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, M{}, K{};
	cin >> N >> M >> K;
	memset(D, -1, sizeof D);
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			int &v = A[i][j];
			cin >> v;
			if (v--) {
				x[v] = i, y[v] = j;
				D[i][j] = v;
			}
		}
	}
	for (int i = 0; i < M; ++i) {
		cin >> B[i];
		--B[i];
	}
	for (int i = 0; i < M; ++i) {
		for (int j = 0; j < 4; ++j) {
			for (int k = 0; k < 4; ++k) {
				cin >> C[i][j][k];
				--C[i][j][k];
			}
		}
	}
	int ans = -1;
	for (int t = 1; t < 1001; ++t) {
		for (int i = M - 1; i >= 0; --i) {
			if (x[i] == -1) {
				continue;
			}
			for (int k = 0; k < 2; ++k) {
				for (int j = 0; j < 4; ++j) {
					int d = C[i][B[i]][j];
					int nx = x[i] + dx[d];
					int ny = y[i] + dy[d];
					if (0 <= nx && nx < N && 0 <= ny && ny < N
							&& (k ? (D[nx][ny] == i && E[nx][ny] >= t - K)
							: (D[nx][ny] == -1 || E[nx][ny] < t - K))) {
						A[nx][ny] = i;
						if (A[x[i]][y[i]] == i) {
							A[x[i]][y[i]] = -1;
						}
						B[i] = d;
						k = 2;
						break;
					}
				}
			}
		}
		fill(x, x + M, -1);
		fill(y, y + M, -1);
		bool f = true;
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < N; ++j) {
				int &v = A[i][j];
				if (v == -1) {
					continue;
				} else if (v) {
					f = false;
				}
				D[i][j] = v;
				E[i][j] = t;
				x[v] = i, y[v] = j;
			}
		}
		if (f) {
			ans = t;
			break;
		}
	}
	cout << ans << "\n";
	return 0;
}
