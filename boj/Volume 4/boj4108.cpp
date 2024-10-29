#include <bits/stdc++.h>

using namespace std;

const int dx[8]{-1, -1, -1, 0, 1, 1, 1, 0};
const int dy[8]{-1, 0, 1, 1, 1, 0, -1, -1};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int R{}, C{};
	while (cin >> R >> C, R) {
		cin.ignore();
		vector<string> A(R);
		for (int i = 0; i < R; ++i) {
			getline(cin, A[i]);
		}
		for (int i = 0; i < R; ++i) {
			for (int j = 0; j < C; ++j) {
				if (A[i][j] == '*') {
					continue;
				}
				int cnt{};
				for (int k = 0; k < 8; ++k) {
					int nx = i + dx[k];
					int ny = j + dy[k];
					if (0 <= nx && nx < R && 0 <= ny && ny < C && A[nx][ny] == '*') {
						++cnt;
					}
				}
				A[i][j] = cnt + '0';
			}
		}
		for (int i = 0; i < R; ++i) {
			cout << A[i] << "\n";
		}
	}
	return 0;
}
