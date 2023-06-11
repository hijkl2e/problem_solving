#include <bits/stdc++.h>

using namespace std;

const int dx[4]{1, -1, 0, 0};
const int dy[4]{0, 0, 1, -1};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	vector<string> A(7);
	for (int i = 0; i < 7; ++i) {
		getline(cin, A[i]);
	}
	int ans{};
	for (int i = 0; i < 7; ++i) {
		for (int j = 0; j < 7; ++j) {
			if (A[i][j] != 'o') {
				continue;
			}
			for (int k = 0; k < 4; ++k) {
				int nx1 = i + dx[k];
				int ny1 = j + dy[k];
				int nx2 = nx1 + dx[k];
				int ny2 = ny1 + dy[k];
				if (0 <= nx2 && nx2 < 7 && 0 <= ny2 && ny2 < 7
						&& A[nx1][ny1] == 'o' && A[nx2][ny2] == '.') {
					++ans;
				}
			}
		}
	}
	cout << ans << "\n";
	return 0;
}
