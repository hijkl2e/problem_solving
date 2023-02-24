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
	vector<vector<int>> D(N, vector<int>(M, -1));
	queue<ii> q;
	D[0][0] = 1;
	q.push({0, 0});
	while (q.size()) {
		auto [x, y] = q.front(); q.pop();
		for (int i = 0; i < 4; ++i) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (0 <= nx && nx < N && 0 <= ny && ny < M && A[nx][ny] == '1' && D[nx][ny] == -1) {
				D[nx][ny] = D[x][y] + 1;
				q.push({nx, ny});
			}
		}
	}
	cout << D[N - 1][M - 1] << "\n";
	return 0;
}
