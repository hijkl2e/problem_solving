#include <bits/stdc++.h>

using namespace std;

using iii = tuple<int, int, int>;

const int INF = 0x3f3f3f3f;
const int dx[12]{1, -1, 0, 0, -2, -1, 1, 2, 2, 1, -1, -2};
const int dy[12]{0, 0, 1, -1, 1, 2, 2, 1, -1, -2, -2, -1};

int D[31][201][201];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int K{}, M{}, N{};
	cin >> K >> M >> N;
	vector<vector<int>> A(N, vector<int>(M));
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			cin >> A[i][j];
		}
	}
	memset(D, 0x3f, sizeof D);
	queue<iii> q;
	D[0][0][0] = 0;
	q.push({0, 0, 0});
	while (q.size()) {
		auto [k, x, y] = q.front(); q.pop();
		for (int i = k == K ? 3 : 11; i >= 0; --i) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			int nk = k + (i > 3);
			if (0 <= nx && nx < N && 0 <= ny && ny < M && A[nx][ny] == 0 && D[nk][nx][ny] == INF) {
				D[nk][nx][ny] = D[k][x][y] + 1;
				q.push({nk, nx, ny});
			}
		}
	}
	int ans = INF;
	for (int i = 0; i <= K; ++i) {
		ans = min(ans, D[i][N - 1][M - 1]);
	}
	cout << (ans == INF ? -1 : ans) << "\n";
	return 0;
}
