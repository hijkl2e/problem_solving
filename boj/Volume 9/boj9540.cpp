#include <bits/stdc++.h>

using namespace std;

const int dx[4]{-1, -1, 1, 1};
const int dy[4]{-1, 1, 1, -1};

vector<string> A(10);
int ans;

void solve(int x, int y, int cnt) {
	ans = max(ans, cnt);
	for (int i = 0; i < 4; ++i) {
		int nx1 = x + dx[i];
		int ny1 = y + dy[i];
		int nx2 = x + 2 * dx[i];
		int ny2 = y + 2 * dy[i];
		if (0 <= nx2 && nx2 < 10 && 0 <= ny2 && ny2 < 10
				&& A[nx1][ny1] == 'B' && A[nx2][ny2] == '#') {
			A[x][y] = A[nx1][ny1] = '#';
			A[nx2][ny2] = 'W';
			solve(nx2, ny2, cnt + 1);
			A[nx2][ny2] = '#';
			A[nx1][ny1] = 'B';
			A[x][y] = 'W';
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T{};
	cin >> T;
	cin.ignore();
	while (T--) {
		getline(cin, A[0]);
		for (int i = 0; i < 10; ++i) {
			getline(cin, A[i]);
		}
		ans = 0;
		for (int i = 0; i < 10; ++i) {
			for (int j = 0; j < 10; ++j) {
				if (A[i][j] == 'W') {
					solve(i, j, 0);
				}
			}
		}
		cout << ans << "\n";
	}
	return 0;
}
