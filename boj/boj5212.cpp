#include <bits/stdc++.h>

using namespace std;

const int dx[4]{1, -1, 0, 0};
const int dy[4]{0, 0, 1, -1};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int R{}, C{};
	cin >> R >> C;
	cin.ignore();
	vector<string> A(R);
	for (int i = 0; i < R; ++i) {
		getline(cin, A[i]);
	}
	vector<string> B(A.begin(), A.end());
	int minx{}, miny{}, maxx{}, maxy{};
	minx = R, miny = C;
	for (int i = 0; i < R; ++i) {
		for (int j = 0; j < C; ++j) {
			if (B[i][j] == '.') {
				continue;
			}
			int cnt{};
			for (int k = 0; k < 4; ++k) {
				int nx = i + dx[k];
				int ny = j + dy[k];
				if (0 <= nx && nx < R && 0 <= ny && ny < C && A[nx][ny] == 'X') {
					++cnt;
				}
			}
			if (cnt < 2) {
				B[i][j] = '.';
			} else {
				minx = min(minx, i);
				maxx = max(maxx, i);
				miny = min(miny, j);
				maxy = max(maxy, j);
			}
		}
	}
	for (int i = minx; i <= maxx; ++i) {
		for (int j = miny; j <= maxy; ++j) {
			cout << B[i][j];
		}
		cout << "\n";
	}
	return 0;
}
