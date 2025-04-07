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
	bool yes = false;
	for (int i = 0; i < R; ++i) {
		for (int j = 0; j < C; ++j) {
			if (A[i][j] == 'X') {
				continue;
			}
			int cnt{};
			for (int k = 0; k < 4; ++k) {
				int nx = i + dx[k];
				int ny = j + dy[k];
				if (0 <= nx && nx < R && 0 <= ny && ny < C && A[nx][ny] == '.') {
					++cnt;
				}
			}
			if (cnt < 2) {
				yes = true;
			}
		}
	}
	cout << yes << "\n";
	return 0;
}
