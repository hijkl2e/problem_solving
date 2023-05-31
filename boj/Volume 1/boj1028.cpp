#include <bits/stdc++.h>

using namespace std;

int R, C;
vector<string> A;

vector<vector<int>> solve() {
	vector<vector<int>> v1(R, vector<int>(C));
	vector<vector<int>> v2(R, vector<int>(C));
	for (int k = 0; k < 2; ++k) {
		vector<vector<int>> &v = k ? v2 : v1;
		for (int i = 0; i < R + C - 1; ++i) {
			int x = max(R - i - 1, 0);
			int y = max(i - R + 1, 0);
			v[x][y] = A[x][y] == '1';
			int nx = x, ny = y;
			while (++nx < R && ++ny < C) {
				v[nx][ny] = A[nx][ny] == '1' ? v[x][y] + 1 : 0;
				x = nx, y = ny;
			}
		}
		reverse(A.begin(), A.end());
	}
	vector<vector<int>> ret(R, vector<int>(C));
	for (int i = 0; i < R; ++i) {
		for (int j = 0; j < C; ++j) {
			ret[i][j] = min(v1[i][j], v2[R - i - 1][j]);
		}
	}
	return ret;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> R >> C;
	cin.ignore();
	A.resize(R);
	for (int i = 0; i < R; ++i) {
		getline(cin, A[i]);
	}
	vector<vector<int>> B = solve();
	for (int i = 0; i < R; ++i) {
		reverse(A[i].begin(), A[i].end());
	}
	vector<vector<int>> D = solve();
	for (int i = 0; i < R; ++i) {
		reverse(D[i].begin(), D[i].end());
	}
	int ans{};
	for (int i = 0; i < R; ++i) {
		for (int j = 0; j < C; ++j) {
			for (int k = ans + 1; k <= D[i][j] && j + 2 * (k - 1) < C; ++k) {
				if (B[i][j + 2 * (k - 1)] >= k) {
					ans = k;
				}
			}
		}
	}
	cout << ans << "\n";
	return 0;
}
