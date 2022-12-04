#include <bits/stdc++.h>

using namespace std;

using ii = pair<int, int>;

const int dx[16]{
	-1, 0, 1, 0, -1, -1, 1, 1,
	-2, -2, -1, 1, 2, 2, 1, -1
};
const int dy[16]{
	0, 1, 0, -1, -1, 1, 1, -1,
	-1, 1, 2, 2, 1, -1, -2, -2
};
const int INF = 1e9 + 7;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	vector<vector<char>> A(N, vector<char>(N));
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			cin >> A[i][j];
		}
	}
	int sc{}, gc{};
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			if (A[i][j] == 'P') {
				sc = i * N + j;
			} else if (A[i][j] == 'K') {
				gc = i * N + j;
			}
		}
	}
	priority_queue<ii, vector<ii>, greater<ii>> pq;
	vector<int> D(N * N, INF);
	pq.push({D[sc] = 0, sc});
	while (pq.size()) {
		auto [d, u] = pq.top(); pq.pop();
		if (D[u] < d) {
			continue;
		}
		int x = u / N;
		int y = u % N;
		if (A[x][y] == 'P' || A[x][y] == 'N') {
			int beg = A[x][y] == 'P' ? 0 : 8;
			int end = beg + 8;
			for (int k = beg; k < end; ++k) {
				int nx = x + dx[k];
				int ny = y + dy[k];
				if (0 <= nx && nx < N && 0 <= ny && ny < N && A[nx][ny] != '0') {
					int v = nx * N + ny;
					int nd = D[u] + k / 8 + 1;
					if (D[v] > nd) {
						pq.push({D[v] = nd, v});
					}
				}
			}
			if (A[x][y] == 'P') {
				A[x][y] = '0';
			}
		} else if (A[x][y] == 'Q' || A[x][y] == 'R' || A[x][y] == 'B') {
			int beg = A[x][y] == 'B' ? 4 : 0;
			int end = A[x][y] == 'R' ? 4 : 8;
			for (int k = beg; k < end; ++k) {
				int nx = x + dx[k];
				int ny = y + dy[k];
				while (0 <= nx && nx < N && 0 <= ny && ny < N && A[nx][ny] == '0') {
					nx += dx[k];
					ny += dy[k];
				}
				if (0 <= nx && nx < N && 0 <= ny && ny < N) {
					int v = nx * N + ny;
					int nd = D[u] + max(abs(x - nx), abs(y - ny));
					if (D[v] > nd) {
						pq.push({D[v] = nd, v});
					}
				}
			}
		}
	}
	cout << (D[gc] == INF ? -1 : D[gc]) << "\n";
	return 0;
}
