#include <bits/stdc++.h>

using namespace std;

using ii = pair<int, int>;
using iii = tuple<int, int, int>;

const int dx[4]{1, -1, 0, 0};
const int dy[4]{0, 0, 1, -1};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, M{}, L{}, E{}, K{};
	cin >> N >> M >> L >> E >> K;
	vector<vector<int>> A(N, vector<int>(M));
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			cin >> A[i][j];
		}
	}
	ii X, Y;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			if (A[i][j] == -3) {
				X = {i, j};
				A[i][j] = -1;
			} else if (A[i][j] == -2) {
				Y = {i, j};
				A[i][j] = K - 1;
			}
		}
	}
	priority_queue<iii, vector<iii>, greater<iii>> pq;
	pq.push({0, X.first, X.second});
	bool yes{};
	while (pq.size()) {
		auto [lev, x, y] = pq.top(); pq.pop();
		if (lev >= L) {
			break;
		}
		yes |= Y.first == x && Y.second == y;
		E += lev;
		if (E >= L) {
			E -= L++;
		}
		for (int i = 0; i < 4; ++i) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (0 <= nx && nx < N && 0 <= ny && ny < M && A[nx][ny] >= 0) {
				pq.push({A[nx][ny], nx, ny});
				A[nx][ny] = -1;
			}
		}
	}
	cout << (yes ? "O" : "X") << "\n";
	return 0;
}
