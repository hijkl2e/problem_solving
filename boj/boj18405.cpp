#include <bits/stdc++.h>

using namespace std;

using ii = pair<int, int>;
using iii = tuple<int, int, int>;

const int dx[4]{1, -1, 0, 0};
const int dy[4]{0, 0, 1, -1};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, K{};
	cin >> N >> K;
	vector<vector<int>> A(N, vector<int>(N));
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			cin >> A[i][j];
		}
	}
	int S{}, X{}, Y{};
	cin >> S >> X >> Y;
	vector<vector<int>> D(N, vector<int>(N, -1));
	vector<iii> B;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			if (A[i][j]) {
				B.push_back({A[i][j], i, j});
			}
		}
	}
	sort(B.begin(), B.end());
	queue<ii> q;
	for (auto &[z, x, y] : B) {
		D[x][y] = 0;
		q.push({x, y});
	}
	while (q.size()) {
		auto [x, y] = q.front(); q.pop();
		if (D[x][y] == S) {
			break;
		}
		for (int i = 0; i < 4; ++i) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (0 <= nx && nx < N && 0 <= ny && ny < N && A[nx][ny] == 0) {
				A[nx][ny] = A[x][y];
				D[nx][ny] = D[x][y] + 1;
				q.push({nx, ny});
			}
		}
	}
	cout << A[X - 1][Y - 1] << "\n";
	return 0;
}
