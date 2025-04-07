#include <bits/stdc++.h>

using namespace std;

using ii = pair<int, int>;

const int dx[4]{1, -1, 0, 0};
const int dy[4]{0, 0, 1, -1};

int N, M, ans;
vector<vector<int>> A;

int solve() {
	vector<deque<bool>> vst(N, deque<bool>(M));
	queue<ii> q;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			if (A[i][j] == 2) {
				vst[i][j] = true;
				q.push({i, j});
			}
		}
	}
	while (q.size()) {
		auto [x, y] = q.front(); q.pop();
		for (int i = 0; i < 4; ++i) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (0 <= nx && nx < N && 0 <= ny && ny < M && A[nx][ny] == 0 && !vst[nx][ny]) {
				vst[nx][ny] = true;
				q.push({nx, ny});
			}
		}
	}
	int cnt{};
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			if (A[i][j] == 0 && !vst[i][j]) {
				++cnt;
			}
		}
	}
	return cnt;
}

void solve(int z, int x, int y) {
	if (z == 3) {
		ans = max(ans, solve());
		return;
	}
	for (int i = x; i < N; ++i) {
		for (int j = i == x ? y : 0; j < M; ++j) {
			if (A[i][j] == 0) {
				A[i][j] = 1;
				solve(z + 1, i, j);
				A[i][j] = 0;
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> N >> M;
	A.assign(N, vector<int>(M));
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			cin >> A[i][j];
		}
	}
	solve(0, 0, 0);
	cout << ans << "\n";
	return 0;
}
