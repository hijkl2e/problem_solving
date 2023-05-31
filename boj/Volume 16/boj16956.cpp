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
	bool yes = true;
	for (int i = 0; i < R; ++i) {
		for (int j = 0; j < C; ++j) {
			if (A[i][j] != 'S') {
				continue;
			}
			for (int k = 0; k < 4; ++k) {
				int nx = i + dx[k];
				int ny = j + dy[k];
				if (0 <= nx && nx < R && 0 <= ny && ny < C) {
					if (A[nx][ny] == '.') {
						A[nx][ny] = 'D';
					} else if (A[nx][ny] == 'W') {
						yes = false;
					}
				}
			}
		}
	}
	cout << yes << "\n";
	if (yes) {
		for (int i = 0; i < R; ++i) {
			cout << A[i] << "\n";
		}
	}
	return 0;
}
