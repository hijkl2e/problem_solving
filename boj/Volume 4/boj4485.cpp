#include <bits/stdc++.h>

using namespace std;

using iii = tuple<int, int, int>;

const int INF = 1e9 + 7;
const int dx[4]{1, -1, 0, 0};
const int dy[4]{0, 0, 1, -1};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	for (int tc = 1; cin >> N, N; ++tc) {
		vector<vector<int>> A(N, vector<int>(N));
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < N; ++j) {
				cin >> A[i][j];
			}
		}
		vector<vector<int>> D(N, vector<int>(N, INF));
		priority_queue<iii, vector<iii>, greater<iii>> pq;
		pq.push({D[0][0] = A[0][0], 0, 0});
		while (pq.size()) {
			auto [d, x, y] = pq.top(); pq.pop();
			for (int i = 0; i < 4; ++i) {
				int nx = x + dx[i];
				int ny = y + dy[i];
				if (0 <= nx && nx < N && 0 <= ny && ny < N && D[nx][ny] > D[x][y] + A[nx][ny]) {
					pq.push({D[nx][ny] = D[x][y] + A[nx][ny], nx, ny});
				}
			}
		}
		cout << "Problem " << tc << ": " << D[N - 1][N - 1] << "\n";
	}
	return 0;
}
