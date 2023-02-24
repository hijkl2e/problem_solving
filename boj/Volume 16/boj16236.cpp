#include <bits/stdc++.h>

using namespace std;

using ii = pair<int, int>;

const int dx[4]{1, -1, 0, 0};
const int dy[4]{0, 0, 1, -1};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	int X{}, Y{};
	vector<vector<int>> A(N, vector<int>(N));
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			cin >> A[i][j];
			if (A[i][j] == 9) {
				X = i, Y = j;
				A[i][j] = 0;
			}
		}
	}
	vector<vector<int>> D(N, vector<int>(N));
	queue<ii> q;
	int sz = 2, exp{}, ans{};
	while (true) {
		for (int i = 0; i < N; ++i) {
			fill(D[i].begin(), D[i].end(), -1);
		}
		D[X][Y] = 0;
		q.push({X, Y});
		while (q.size()) {
			auto [x, y] = q.front(); q.pop();
			for (int i = 0; i < 4; ++i) {
				int nx = x + dx[i];
				int ny = y + dy[i];
				if (0 <= nx && nx < N && 0 <= ny && ny < N && A[nx][ny] <= sz && D[nx][ny] == -1) {
					D[nx][ny] = D[x][y] + 1;
					q.push({nx, ny});
				}
			}
		}
		X = Y = -1;
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < N; ++j) {
				if (D[i][j] == -1 || A[i][j] >= sz || A[i][j] == 0) {
					continue;
				}
				if (X == -1 || D[X][Y] > D[i][j]) {
					X = i, Y = j;
				}
			}
		}
		if (X == -1) {
			break;
		}
		ans += D[X][Y];
		if (++exp == sz) {
			++sz, exp = 0;
		}
		A[X][Y] = 0;
	}
	cout << ans << "\n";
	return 0;
}
