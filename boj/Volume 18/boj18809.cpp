#include <bits/stdc++.h>

using namespace std;

using ii = pair<int, int>;

const int dx[4]{1, -1, 0, 0};
const int dy[4]{0, 0, 1, -1};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, M{}, G{}, R{};
	cin >> N >> M >> G >> R;
	vector<vector<int>> A(N, vector<int>(M));
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			cin >> A[i][j];
		}
	}
	vector<ii> B;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			if (A[i][j] == 2) {
				B.push_back({i, j});
			}
		}
	}
	vector<int> C(B.size() - G - R, 2);
	while (G--) {
		C.push_back(4);
	}
	while (R--) {
		C.push_back(8);
	}
	vector<vector<int>> D(N, vector<int>(M));
	vector<vector<int>> E(N, vector<int>(M));
	int ans{};
	do {
		for (int i = 0; i < N; ++i) {
			fill(D[i].begin(), D[i].end(), -1);
			fill(E[i].begin(), E[i].end(), 0);
		}
		queue<ii> q;
		for (int i = 0; i < B.size(); ++i) {
			auto &[x, y] = B[i];
			if (C[i] == 4 || C[i] == 8) {
				D[x][y] = 0;
				E[x][y] = C[i];
				q.push({x, y});
			}
		}
		int cnt{};
		while (q.size()) {
			auto [x, y] = q.front(); q.pop();
			if (E[x][y] == 12) {
				++cnt;
				continue;
			}
			for (int i = 0; i < 4; ++i) {
				int nx = x + dx[i];
				int ny = y + dy[i];
				if (0 <= nx && nx < N && 0 <= ny && ny < M && A[nx][ny]) {
					if (D[nx][ny] == -1 || D[nx][ny] == D[x][y] + 1) {
						E[nx][ny] |= E[x][y];
						if (D[nx][ny] == -1) {
							D[nx][ny] = D[x][y] + 1;
							q.push({nx, ny});
						}
					}
				}
			}
		}
		ans = max(ans, cnt);
	} while (next_permutation(C.begin(), C.end()));
	cout << ans << "\n";
	return 0;
}
