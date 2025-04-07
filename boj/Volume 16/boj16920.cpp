#include <bits/stdc++.h>

using namespace std;

using ii = pair<int, int>;

const int dx[4]{1, -1, 0, 0};
const int dy[4]{0, 0, 1, -1};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, M{}, P{};
	cin >> N >> M >> P;
	vector<int> S(P + 1);
	for (int i = 1; i <= P; ++i) {
		cin >> S[i];
		S[i] = min(S[i], N * M);
	}
	cin.ignore();
	vector<string> A(N);
	for (int i = 0; i < N; ++i) {
		getline(cin, A[i]);
	}
	vector<vector<int>> D(N, vector<int>(M, -1));
	vector<queue<ii>> q(P + 1);
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			if (isdigit(A[i][j])) {
				D[i][j] = 0;
				q[A[i][j] - '0'].push({i, j});
			}
		}
	}
	for (int i = 1;; ++i) {
		int sz{};
		for (int j = 1; j <= P; ++j) {
			while (q[j].size()) {
				auto [x, y] = q[j].front();
				if (D[x][y] == i * S[j]) {
					break;
				}
				q[j].pop();
				for (int k = 0; k < 4; ++k) {
					int nx = x + dx[k];
					int ny = y + dy[k];
					if (0 <= nx && nx < N && 0 <= ny && ny < M && A[nx][ny] == '.') {
						A[nx][ny] = j + '0';
						D[nx][ny] = D[x][y] + 1;
						q[j].push({nx, ny});
					}
				}
			}
			sz += q[j].size();
		}
		if (sz == 0) {
			break;
		}
	}
	vector<int> B(P + 1);
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			if (isdigit(A[i][j])) {
				++B[A[i][j] - '0'];
			}
		}
	}
	for (int i = 1; i <= P; ++i) {
		cout << B[i] << (i == P ? "\n" : " ");
	}
	return 0;
}
