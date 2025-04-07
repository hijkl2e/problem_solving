#include <bits/stdc++.h>

using namespace std;

const int dx[4]{-1, 1, 0, 0};
const int dy[4]{0, 0, -1, 1};

int ans;
vector<string> A(5);

void solve(int step) {
	ans = max(ans, step);
	for (int i = 0; i < 5; ++i) {
		for (int j = 0; j < 9; ++j) {
			if (A[i][j] != 'o') {
				continue;
			}
			for (int k = 0; k < 4; ++k) {
				int nx1 = i + dx[k];
				int ny1 = j + dy[k];
				int nx2 = i + 2 * dx[k];
				int ny2 = j + 2 * dy[k];
				if (0 <= nx2 && nx2 < 5 && 0 <= ny2 && ny2 < 9
						&& A[nx1][ny1] == 'o' && A[nx2][ny2] == '.') {
					A[nx2][ny2] = 'o';
					A[i][j] = A[nx1][ny1] = '.';
					solve(step + 1);
					A[i][j] = A[nx1][ny1] = 'o';
					A[nx2][ny2] = '.';
				}
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T{};
	cin >> T;
	while (T--) {
		getline(cin, A[0]);
		for (int i = 0; i < 5; ++i) {
			getline(cin, A[i]);
		}
		int cnt{};
		for (int i = 0; i < 5; ++i) {
			cnt += count(A[i].begin(), A[i].end(), 'o');
		}
		ans = 0;
		solve(0);
		cout << cnt - ans << " " << ans << "\n";
	}
	return 0;
}
