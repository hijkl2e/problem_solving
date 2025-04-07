#include <bits/stdc++.h>

using namespace std;

const int dx[4]{1, -1, 0, 0};
const int dy[4]{0, 0, 1, -1};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int H{}, W{};
	cin >> H >> W;
	vector<vector<int>> A(H, vector<int>(W));
	for (int i = 0; i < H; ++i) {
		for (int j = 0; j < W; ++j) {
			cin >> A[i][j];
		}
	}
	vector<deque<bool>> B(H, deque<bool>(W, true));
	bool yes = true;
	for (int i = 0; i < H; ++i) {
		for (int j = 0; j < W; ++j) {
			if (A[i][j] <= 0) {
				B[i][j] = false;
				continue;
			}
			for (int k = 0; k < 4; ++k) {
				int nx = i + dx[k];
				int ny = j + dy[k];
				if (0 <= nx && nx < H && 0 <= ny && ny < W) {
					if (A[i][j] + 1 == A[nx][ny]) {
						B[i][j] = false;
					} else if (A[nx][ny] != -1 && abs(A[i][j] - A[nx][ny]) > 1) {
						yes = false;
					}
				}
			}
		}
	}
	int ans{};
	for (int i = 0; i < H; ++i) {
		ans += accumulate(B[i].begin(), B[i].end(), 0);
	}
	cout << (yes ? ans : -1) << "\n";
	return 0;
}
