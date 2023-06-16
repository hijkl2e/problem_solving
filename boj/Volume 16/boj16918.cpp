#include <bits/stdc++.h>

using namespace std;

const int dx[4]{1, -1, 0, 0};
const int dy[4]{0, 0, 1, -1};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int R{}, C{}, N{};
	cin >> R >> C >> N;
	cin.ignore();
	vector<string> A(R);
	for (int i = 0; i < R; ++i) {
		getline(cin, A[i]);
	}
	vector<vector<int>> B(R, vector<int>(C, -1));
	for (int i = 0; i < R; ++i) {
		for (int j = 0; j < C; ++j) {
			if (A[i][j] == 'O') {
				B[i][j] = 3;
			}
		}
	}
	for (int t = 1; t <= N; ++t) {
		for (int i = 0; i < R; ++i) {
			for (int j = 0; j < C; ++j) {
				if (t % 2 == 0) {
					if (B[i][j] == -1) {
						B[i][j] = t + 3;
					}
					continue;
				} else if (B[i][j] == -1 || B[i][j] > t) {
					continue;
				}
				B[i][j] = -1;
				for (int k = 0; k < 4; ++k) {
					int nx = i + dx[k];
					int ny = j + dy[k];
					if (0 <= nx && nx < R && 0 <= ny && ny < C && B[nx][ny] > t) {
						B[nx][ny] = -1;
					}
				}
			}
		}
	}
	for (int i = 0; i < R; ++i) {
		for (int j = 0; j < C; ++j) {
			cout << (B[i][j] == -1 ? '.' : 'O');
		}
		cout << "\n";
	}
	return 0;
}
