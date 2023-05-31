#include <bits/stdc++.h>

using namespace std;

using ii = pair<int, int>;

const int dx[4]{1, -1, 0, 0};
const int dy[4]{0, 0, 1, -1};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, M{};
	cin >> N >> M;
	vector<vector<int>> A(N, vector<int>(M));
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			cin >> A[i][j];
		}
	}
	int h{}, w{}, sr{}, sc{}, fr{}, fc{};
	cin >> h >> w >> sr >> sc >> fr >> fc;
	--sr, --sc, --fr, --fc;
	if (fr >= N - h + 1 || fc >= M - w + 1) {
		cout << "-1\n";
		return 0;
	}
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			A[i][j] += (i ? A[i - 1][j] : 0) + (j ? A[i][j - 1] : 0) - (i && j ? A[i - 1][j - 1] : 0);
		}
	}
	N -= h - 1;
	M -= w - 1;
	vector<deque<bool>> B(N, deque<bool>(M));
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			int x = i + h - 1;
			int y = j + w - 1;
			int z = A[x][y] - (i ? A[i - 1][y] : 0) - (j ? A[x][j - 1] : 0) + (i && j ? A[i - 1][j - 1] : 0);
			B[i][j] = z == 0;
		}
	}
	vector<vector<int>> D(N, vector<int>(M, -1));
	queue<ii> q;
	D[sr][sc] = 0;
	q.push({sr, sc});
	while (q.size()) {
		auto [x, y] = q.front(); q.pop();
		for (int i = 0; i < 4; ++i) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (0 <= nx && nx < N && 0 <= ny && ny < M && B[nx][ny] && D[nx][ny] == -1) {
				D[nx][ny] = D[x][y] + 1;
				q.push({nx, ny});
			}
		}
	}
	cout << D[fr][fc] << "\n";
	return 0;
}
