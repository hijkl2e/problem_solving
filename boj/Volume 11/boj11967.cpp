#include <bits/stdc++.h>

using namespace std;

using ii = pair<int, int>;

const int dx[4]{1, -1, 0, 0};
const int dy[4]{0, 0, 1, -1};

vector<ii> G[101][101];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, M{};
	cin >> N >> M;
	while (M--) {
		int x{}, y{}, a{}, b{};
		cin >> x >> y >> a >> b;
		G[x][y].push_back({a, b});
	}
	vector<deque<bool>> A(N + 1, deque<bool>(N + 1));
	vector<deque<bool>> B(N + 1, deque<bool>(N + 1));
	A[1][1] = B[1][1] = true;
	queue<ii> q;
	q.push({1, 1});
	while (q.size()) {
		auto [x, y] = q.front(); q.pop();
		for (auto &[nx, ny] : G[x][y]) {
			if (A[nx][ny] && !B[nx][ny]) {
				q.push({nx, ny});
			}
			B[nx][ny] = true;
		}
		for (int i = 0; i < 4; ++i) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (0 < nx && nx <= N && 0 < ny && ny <= N) {
				if (!A[nx][ny] && B[nx][ny]) {
					q.push({nx, ny});
				}
				A[nx][ny] = true;
			}
		}
	}
	int ans{};
	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= N; ++j) {
			if (B[i][j]) {
				++ans;
			}
		}
	}
	cout << ans << "\n";
	return 0;
}
