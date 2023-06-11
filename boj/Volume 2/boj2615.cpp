#include <bits/stdc++.h>

using namespace std;

const int dx[4]{0, 1, 1, -1};
const int dy[4]{1, 0, 1, 1};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	vector<vector<int>> A(21, vector<int>(21));
	for (int i = 1; i < 20; ++i) {
		for (int j = 1; j < 20; ++j) {
			cin >> A[i][j];
		}
	}
	int ans_x{}, ans_y{};
	for (int i = 1; i < 20; ++i) {
		for (int j = 1; j < 20; ++j) {
			if (A[i][j] == 0) {
				continue;
			}
			for (int k = 0; k < 4; ++k) {
				if (A[i][j] == A[i - dx[k]][j - dy[k]]) {
					continue;
				}
				int nx = i, ny = j;
				int cnt{};
				while (A[i][j] == A[nx][ny]) {
					++cnt;
					nx += dx[k];
					ny += dy[k];
				}
				if (cnt == 5) {
					ans_x = i, ans_y = j;
				}
			}
		}
	}
	cout << A[ans_x][ans_y] << "\n";
	if (A[ans_x][ans_y]) {
		cout << ans_x << " " << ans_y << "\n";
	}
	return 0;
}
