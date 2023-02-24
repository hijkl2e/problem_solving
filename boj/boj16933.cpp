#include <bits/stdc++.h>

using namespace std;

using iii = tuple<int, int, int>;

const int dx[4]{1, -1, 0, 0};
const int dy[4]{0, 0, 1, -1};

int B[2][1001][1001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, M{}, K{};
	cin >> N >> M >> K;
	cin.ignore();
	vector<string> A(N);
	for (int i = 0; i < N; ++i) {
		getline(cin, A[i]);
	}
	for (int i = 0; i < 2; ++i) {
		for (int j = 0; j < N; ++j) {
			for (int k = 0; k < M; ++k) {
				B[i][j][k] = K + 1;
			}
		}
	}
	queue<iii> q;
	B[0][0][0] = 0;
	q.push({0, 0, 0});
	int ans = -1;
	for (int d = 1; q.size(); ++d) {
		int sz = q.size();
		while (sz--) {
			auto [t, x, y] = q.front(); q.pop();
			if (x == N - 1 && y == M - 1) {
				ans = d;
				while (q.size()) {
					q.pop();
				}
				break;
			}
			int nt = t ^ 1;
			for (int i = 0; i < 4; ++i) {
				int nx = x + dx[i];
				int ny = y + dy[i];
				if (0 <= nx && nx < N && 0 <= ny && ny < M && (d % 2 || A[nx][ny] == '0')) {
					int nb = B[t][x][y] + A[nx][ny] - '0';
					if (B[nt][nx][ny] > nb) {
						B[nt][nx][ny] = nb;
						q.push({nt, nx, ny});
					}
				}
			}
			if (B[nt][x][y] > B[t][x][y]) {
				B[nt][x][y] = B[t][x][y];
				q.push({nt, x, y});
			}
		}
	}
	cout << ans << "\n";
	return 0;
}
