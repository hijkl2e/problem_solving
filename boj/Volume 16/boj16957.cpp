#include <bits/stdc++.h>

using namespace std;

using ii = pair<int, int>;

const int INF = 1e9 + 7;
const int dx[8]{-1, -1, -1, 0, 1, 1, 1, 0};
const int dy[8]{-1, 0, 1, 1, 1, 0, -1, -1};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int R{}, C{};
	cin >> R >> C;
	vector<vector<int>> A(R, vector<int>(C));
	for (int i = 0; i < R; ++i) {
		for (int j = 0; j < C; ++j) {
			cin >> A[i][j];
		}
	}
	vector<ii> B(300001, {-1, -1});
	vector<int> D(300001);
	for (int i = 0; i < R; ++i) {
		for (int j = 0; j < C; ++j) {
			B[A[i][j]] = {i, j};
			D[A[i][j]] = 1;
		}
	}
	for (int i = D.size() - 1; i >= 0; --i) {
		if (D[i] == 0) {
			continue;
		}
		auto &[x, y] = B[i];
		int minv = INF;
		for (int k = 0; k < 8; ++k) {
			int nx = x + dx[k];
			int ny = y + dy[k];
			if (0 <= nx && nx < R && 0 <= ny && ny < C) {
				minv = min(minv, A[nx][ny]);
			}
		}
		if (minv < i) {
			D[minv] += D[i];
			D[i] = 0;
		}
	}
	for (int i = 0; i < R; ++i) {
		for (int j = 0; j < C; ++j) {
			cout << D[A[i][j]] << (j == C - 1 ? "\n" : " ");
		}
	}
	return 0;
}
