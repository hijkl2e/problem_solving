#include <bits/stdc++.h>

using namespace std;

const int dx[16]{-1, -1, -1, 0, 1, 1, 1, 0, -2, -2, -1, 1, 2, 2, 1, -1};
const int dy[16]{-1, 0, 1, 1, 1, 0, -1, -1, -1, 1, 2, 2, 1, -1, -2, -2};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, M{};
	cin >> N >> M;
	vector<string> A(N + 1, string(M + 1, '.'));
	int Q{};
	cin >> Q;
	while (Q--) {
		int x{}, y{};
		cin >> x >> y;
		A[x][y] = 'Q';
	}
	int K{};
	cin >> K;
	while (K--) {
		int x{}, y{};
		cin >> x >> y;
		A[x][y] = 'K';
	}
	int P{};
	cin >> P;
	while (P--) {
		int x{}, y{};
		cin >> x >> y;
		A[x][y] = 'P';
	}
	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= M; ++j) {
			if (A[i][j] == 'Q') {
				for (int k = 0; k < 8; ++k) {
					int nx = i + dx[k];
					int ny = j + dy[k];
					while (1 <= nx && nx <= N && 1 <= ny && ny <= M
							&& (A[nx][ny] == '.' || A[nx][ny] == 'X')) {
						A[nx][ny] = 'X';
						nx += dx[k];
						ny += dy[k];
					}
				}
			} else if (A[i][j] == 'K') {
				for (int k = 8; k < 16; ++k) {
					int nx = i + dx[k];
					int ny = j + dy[k];
					if (1 <= nx && nx <= N && 1 <= ny && ny <= M && A[nx][ny] == '.') {
						A[nx][ny] = 'X';
					}
				}
			}
		}
	}
	int ans{};
	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= M; ++j) {
			if (A[i][j] == '.') {
				++ans;
			}
		}
	}
	cout << ans << "\n";
	return 0;
}
