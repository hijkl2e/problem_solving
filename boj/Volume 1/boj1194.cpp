#include <bits/stdc++.h>

using namespace std;

using iii = tuple<int, int, int>;

const int INF = 0x3f3f3f3f;
const int dx[4]{1, -1, 0, 0};
const int dy[4]{0, 0, 1, -1};

int D[64][51][51];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, M{};
	cin >> N >> M;
	cin.ignore();
	vector<string> A(N);
	for (int i = 0; i < N; ++i) {
		getline(cin, A[i]);
	}
	int sx{}, sy{};
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			if (A[i][j] == '0') {
				sx = i, sy = j;
			}
		}
	}
	memset(D, 0x3f, sizeof D);
	queue<iii> q;
	D[0][sx][sy] = 0;
	q.push({0, sx, sy});
	while (q.size()) {
		auto [z, x, y] = q.front(); q.pop();
		for (int i = 0; i < 4; ++i) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (0 <= nx && nx < N && 0 <= ny && ny < M && A[nx][ny] != '#'
					&& (!isupper(A[nx][ny]) || (z & (1 << (A[nx][ny] - 'A'))))) {
				int nz = z;
				if (islower(A[nx][ny])) {
					nz |= 1 << (A[nx][ny] - 'a');
				}
				if (D[nz][nx][ny] == INF) {
					D[nz][nx][ny] = D[z][x][y] + 1;
					q.push({nz, nx, ny});
				}
			}
		}
	}
	int ans = INF;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			if (A[i][j] != '1') {
				continue;
			}
			for (int k = 0; k < 64; ++k) {
				ans = min(ans, D[k][i][j]);
			}
		}
	}
	cout << (ans == INF ? -1 : ans) << "\n";
	return 0;
}
