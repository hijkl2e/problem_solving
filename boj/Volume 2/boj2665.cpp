#include <bits/stdc++.h>

using namespace std;

using ii = pair<int, int>;

const int INF = 1e9 + 7;
const int dx[4]{1, -1, 0, 0};
const int dy[4]{0, 0, 1, -1};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	cin.ignore();
	vector<string> A(N);
	for (int i = 0; i < N; ++i) {
		getline(cin, A[i]);
	}
	vector<vector<int>> D(N, vector<int>(N, INF));
	deque<ii> dq;
	D[0][0] = 0;
	dq.push_back({0, 0});
	while (dq.size()) {
		auto [x, y] = dq.front(); dq.pop_front();
		for (int i = 0; i < 4; ++i) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (0 <= nx && nx < N && 0 <= ny && ny < N && D[nx][ny] > D[x][y] - A[nx][ny] + '1') {
				D[nx][ny] = D[x][y] - A[nx][ny] + '1';
				if (A[nx][ny]) {
					dq.push_front({nx, ny});
				} else {
					dq.push_back({nx, ny});
				}
			}
		}
	}
	cout << D[N - 1][N - 1] << "\n";
	return 0;
}
