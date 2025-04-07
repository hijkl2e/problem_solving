#include <bits/stdc++.h>

using namespace std;

using point = tuple<int, int, int, int, int>;

const int INF = 1e9 + 7;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, M{}, K{};
	cin >> N >> M >> K;
	vector<vector<int>> A(N, vector<int>(M));
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			cin >> A[i][j];
		}
	}
	vector<vector<int>> B(5, vector<int>(5));
	for (int i = 0; i < 5; ++i) {
		for (int j = 0; j < 5; ++j) {
			cin >> B[i][j];
		}
	}
	B[1][2] = B[2][1] = B[2][3] = B[3][2] = 2;
	vector<vector<int>> D[2][31];
	for (int i = 0; i < 2; ++i) {
		for (int j = 0; j <= K; ++j) {
			D[i][j].assign(N, vector<int>(M, INF));
		}
	}
	queue<point> q;
	D[0][0][0][0] = 0;
	q.push({0, 0, 0, 0, 0});
	while (q.size()) {
		auto [u, v, x, y, d] = q.front(); q.pop();
		for (int i = 0; i < 5; ++i) {
			for (int j = 0; j < 5; ++j) {
				if (B[i][j] == 0 || (B[i][j] == 1 && v == K)) {
					continue;
				}
				int nx = x + i - 2;
				int ny = y + j - 2;
				if (nx < 0 || nx >= N || ny < 0 || ny >= M || A[nx][ny] == 1) {
					continue;
				}
				int nu = u | (A[nx][ny] == 2);
				int nv = v + (B[i][j] == 1);
				auto &nd = D[nu][nv][nx][ny];
				if (nd == INF) {
					nd = d + 1;
					q.push({nu, nv, nx, ny, nd});
				}
			}
		}
	}
	int ans = INF;
	for (int i = 0; i <= K; ++i) {
		ans = min(ans, D[1][i][N - 1][M - 1]);
	}
	cout << (ans == INF ? -1 : ans) << "\n";
	return 0;
}
