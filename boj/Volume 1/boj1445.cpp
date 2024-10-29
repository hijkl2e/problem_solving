#include <bits/stdc++.h>

using namespace std;

using ii = pair<int, int>;
using iiii = pair<ii, ii>;

const int INF = 1e9 + 7;
const int dx[4]{1, 0, -1, 0};
const int dy[4]{0, 1, 0, -1};

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
	vector<deque<bool>> B(N, deque<bool>(M));
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			for (int k = 0; k < 4; ++k) {
				int nx = i + dx[k];
				int ny = j + dy[k];
				if (0 <= nx && nx < N && 0 <= ny && ny < M && A[nx][ny] == 'g') {
					B[i][j] = true;
					break;
				}
			}
		}
	}
	int sx{}, sy{}, fx{}, fy{};
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			if (A[i][j] == 'S') {
				sx = i, sy = j;
			} else if (A[i][j] == 'F') {
				fx = i, fy = j;
			}
		}
	}
	vector<vector<ii>> D(N, vector<ii>(M, {INF, INF}));
	priority_queue<iiii, vector<iiii>, greater<iiii>> pq;
	pq.push({D[sx][sy] = {0, 0}, {sx, sy}});
	while (pq.size()) {
		auto [a, b] = pq.top(); pq.pop();
		auto &[d1, d2] = a;
		auto &[x, y] = b;
		if (D[x][y] < a) {
			continue;
		}
		for (int i = 0; i < 4; ++i) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (0 <= nx && nx < N && 0 <= ny && ny < M) {
				ii nd = a;
				if (A[nx][ny] == 'g') {
					++nd.first;
				} else if (A[nx][ny] == '.' && B[nx][ny]) {
					++nd.second;
				}
				if (D[nx][ny] > nd) {
					pq.push({D[nx][ny] = nd, {nx, ny}});
				}
			}
		}
	}
	auto &[d1, d2] = D[fx][fy];
	cout << d1 << " " << d2 << "\n";
	return 0;
}
