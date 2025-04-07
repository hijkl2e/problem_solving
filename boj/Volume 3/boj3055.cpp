#include <bits/stdc++.h>

using namespace std;

using ii = pair<int, int>;

const int INF = 1e9 + 7;
const int dx[4]{1, -1, 0, 0};
const int dy[4]{0, 0, 1, -1};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int R{}, C{};
	cin >> R >> C;
	cin.ignore();
	vector<string> A(R);
	for (int i = 0; i < R; ++i) {
		getline(cin, A[i]);
	}
	vector<vector<int>> B(R, vector<int>(C, INF));
	queue<ii> q;
	for (int i = 0; i < R; ++i) {
		for (int j = 0; j < C; ++j) {
			if (A[i][j] == '*') {
				B[i][j] = 0;
				q.push({i, j});
			}
		}
	}
	while (q.size()) {
		auto [x, y] = q.front(); q.pop();
		for (int i = 0; i < 4; ++i) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (0 <= nx && nx < R && 0 <= ny && ny < C && B[nx][ny] == INF
					&& A[nx][ny] != 'X' && A[nx][ny] != 'D') {
				B[nx][ny] = B[x][y] + 1;
				q.push({nx, ny});
			}
		}
	}
	int gx{}, gy{};
	vector<vector<int>> D(R, vector<int>(C, INF));
	for (int i = 0; i < R; ++i) {
		for (int j = 0; j < C; ++j) {
			if (A[i][j] == 'S') {
				D[i][j] = 0;
				q.push({i, j});
			} else if (A[i][j] == 'D') {
				gx = i, gy = j;
			}
		}
	}
	while (q.size()) {
		auto [x, y] = q.front(); q.pop();
		for (int i = 0; i < 4; ++i) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (0 <= nx && nx < R && 0 <= ny && ny < C && D[nx][ny] == INF
					&& A[nx][ny] != 'X' && D[x][y] + 1 < B[nx][ny]) {
				D[nx][ny] = D[x][y] + 1;
				q.push({nx, ny});
			}
		}
	}
	if (D[gx][gy] == INF) {
		cout << "KAKTUS\n";
	} else {
		cout << D[gx][gy] << "\n";
	}
	return 0;
}
