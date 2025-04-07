#include <bits/stdc++.h>

using namespace std;

using rec = tuple<int, int, int, int>;

const int INF = 0x3f3f3f3f;
const int dx[4]{1, -1, 0, 0};
const int dy[4]{0, 0, 1, -1};

int D[22][22][22][22];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, M{};
	cin >> N >> M;
	cin.ignore();
	vector<string> A(N + 2);
	A[0] = A[N + 1] = string(M + 2, '.');
	for (int i = 1; i <= N; ++i) {
		getline(cin, A[i]);
		A[i] = "." + A[i] + ".";
	}
	int x1{}, y1{}, x2{}, y2{};
	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= M; ++j) {
			if (A[i][j] == 'o') {
				if (x1 == 0) {
					x1 = i, y1 = j;
				} else {
					x2 = i, y2 = j;
				}
			}
		}
	}
	memset(D, 0x3f, sizeof D);
	queue<rec> q;
	D[x1][y1][x2][y2] = 0;
	q.push({x1, y1, x2, y2});
	while (q.size()) {
		tie(x1, y1, x2, y2) = q.front(); q.pop();
		if (x1 % (N + 1) == 0 || y1 % (M + 1) == 0 || x2 % (N + 1) == 0 || y2 % (M + 1) == 0) {
			continue;
		}
		for (int i = 0; i < 4; ++i) {
			int nx1 = x1 + dx[i];
			int ny1 = y1 + dy[i];
			int nx2 = x2 + dx[i];
			int ny2 = y2 + dy[i];
			if (A[nx1][ny1] == '#') {
				nx1 = x1, ny1 = y1;
			}
			if (A[nx2][ny2] == '#') {
				nx2 = x2, ny2 = y2;
			}
			if (D[nx1][ny1][nx2][ny2] == INF) {
				D[nx1][ny1][nx2][ny2] = D[x1][y1][x2][y2] + 1;
				q.push({nx1, ny1, nx2, ny2});
			}
		}
	}
	int ans = INF;
	for (int i = 0; i < N + 2; ++i) {
		for (int j = 0; j < M + 2; ++j) {
			for (int k = 0; k < N + 2; ++k) {
				for (int l = 0; l < M + 2; ++l) {
					if ((i % (N + 1) == 0 || j % (M + 1) == 0) ^ (k % (N + 1) == 0 || l % (M + 1) == 0)) {
						ans = min(ans, D[i][j][k][l]);
					}
				}
			}
		}
	}
	cout << (ans > 10 ? -1 : ans) << "\n";
	return 0;
}
