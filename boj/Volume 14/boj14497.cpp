#include <bits/stdc++.h>

using namespace std;

using ii = pair<int, int>;

const int INF = 1e9 + 7;
const int dx[4]{1, -1, 0, 0};
const int dy[4]{0, 0, 1, -1};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, M{};
	cin >> N >> M;
	int x1{}, y1{}, x2{}, y2{};
	cin >> x1 >> y1 >> x2 >> y2;
	--x1, --y1, --x2, --y2;
	cin.ignore();
	vector<string> A(N);
	for (int i = 0; i < N; ++i) {
		getline(cin, A[i]);
	}
	A[x1][y1] = '0', A[x2][y2] = '1';
	vector<vector<int>> D(N, vector<int>(M, INF));
	deque<ii> dq;
	D[x1][y1] = 0;
	dq.push_back({x1, y1});
	while (dq.size()) {
		auto [x, y] = dq.front(); dq.pop_front();
		for (int i = 0; i < 4; ++i) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (0 <= nx && nx < N && 0 <= ny && ny < M && D[nx][ny] > D[x][y] + A[nx][ny] - '0') {
				D[nx][ny] = D[x][y] + A[nx][ny] - '0';
				if (A[nx][ny]) {
					dq.push_back({nx, ny});
				} else {
					dq.push_front({nx, ny});
				}
			}
		}
	}
	cout << D[x2][y2] << "\n";
	return 0;
}
