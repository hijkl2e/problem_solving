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
	if (N * M % 2) {
		cout << "-1\n";
		return 0;
	}
	vector<vector<int>> A(N, vector<int>(M));
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			cin >> A[i][j];
		}
	}
	int cnt{};
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			cnt += A[i][j];
		}
	}
	if (cnt % 2) {
		cout << "-1\n";
		return 0;
	}
	vector<deque<bool>> vst(N, deque<bool>(M));
	vector<deque<ii>> dq(2);
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			for (int k = 0; k < 4; ++k) {
				int nx = i + dx[k];
				int ny = j + dy[k];
				if (0 <= nx && nx < N && 0 <= ny && ny < M && A[i][j] == A[nx][ny]) {
					vst[i][j] = vst[nx][ny] = true;
					dq[A[i][j]].push_back({i, j});
					dq[A[nx][ny]].push_back({nx, ny});
					i = N, j = M;
					break;
				}
			}
		}
	}
	if (dq[0].empty() && dq[1].empty()) {
		cout << "-1\n";
		return 0;
	}
	cout << "1\n";
	while (dq[0].size() || dq[1].size()) {
		for (int i = 0; i < 2; ++i) {
			if (dq[i].size() < 2) {
				continue;
			}
			cout << dq[i][0].first + 1 << " " << dq[i][0].second + 1 << " ";
			cout << dq[i][1].first + 1 << " " << dq[i][1].second + 1 << "\n";
			for (int j = 0; j < 2; ++j) {
				auto [x, y] = dq[i].front(); dq[i].pop_front();
				for (int k = 0; k < 4; ++k) {
					int nx = x + dx[k];
					int ny = y + dy[k];
					if (0 <= nx && nx < N && 0 <= ny && ny < M && !vst[nx][ny]) {
						vst[nx][ny] = true;
						dq[A[nx][ny]].push_back({nx, ny});
					}
				}
			}
		}
	}
	return 0;
}
