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
	cin.ignore();
	vector<string> A(N);
	for (int i = 0; i < N; ++i) {
		getline(cin, A[i]);
	}
	vector<vector<int>> B(N, vector<int>(M, 2));
	queue<ii> q;
	B[0][0] = 0;
	q.push({0, 0});
	int ans = -1;
	for (int d = 1; q.size(); ++d) {
		int sz = q.size();
		while (sz--) {
			auto [x, y] = q.front(); q.pop();
			if (x == N - 1 && y == M - 1) {
				ans = d;
				while (q.size()) {
					q.pop();
				}
				break;
			}
			for (int i = 0; i < 4; ++i) {
				int nx = x + dx[i];
				int ny = y + dy[i];
				if (0 <= nx && nx < N && 0 <= ny && ny < M) {
					int nb = B[x][y] + A[nx][ny] - '0';
					if (B[nx][ny] > nb) {
						B[nx][ny] = nb;
						q.push({nx, ny});
					}
				}
			}
		}
	}
	cout << ans << "\n";
	return 0;
}
