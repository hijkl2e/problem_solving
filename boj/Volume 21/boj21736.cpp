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
	int sx{}, sy{};
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			if (A[i][j] == 'I') {
				sx = i, sy = j;
			}
		}
	}
	vector<deque<bool>> vst(N, deque<bool>(M));
	queue<ii> q;
	vst[sx][sy] = true;
	q.push({sx, sy});
	int ans{};
	while (q.size()) {
		auto [x, y] = q.front(); q.pop();
		for (int i = 0; i < 4; ++i) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (0 <= nx && nx < N && 0 <= ny && ny < M && A[nx][ny] != 'X' && !vst[nx][ny]) {
				vst[nx][ny] = true;
				q.push({nx, ny});
				if (A[nx][ny] == 'P') {
					++ans;
				}
			}
		}
	}
	if (ans) {
		cout << ans << "\n";
	} else {
		cout << "TT\n";
	}
	return 0;
}
