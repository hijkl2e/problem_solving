#include <bits/stdc++.h>

using namespace std;

const int dx[8]{-1, -1, -1, 0, 1, 1, 1, 0};
const int dy[8]{-1, 0, 1, 1, 1, 0, -1, -1};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int R{}, S{};
	cin >> R >> S;
	cin.ignore();
	vector<string> A(R);
	for (int i = 0; i < R; ++i) {
		getline(cin, A[i]);
	}
	int ans{}, maxv{};
	for (int i = 0; i < R; ++i) {
		for (int j = 0; j < S; ++j) {
			int cnt{};
			for (int k = 0; k < 8; ++k) {
				int nx = i + dx[k];
				int ny = j + dy[k];
				if (0 <= nx && nx < R && 0 <= ny && ny < S && A[nx][ny] == 'o') {
					++cnt;
				}
			}
			if (A[i][j] == '.') {
				maxv = max(maxv, cnt);
			} else {
				ans += cnt;
			}
		}
	}
	ans = ans / 2 + maxv;
	cout << ans << "\n";
	return 0;
}
