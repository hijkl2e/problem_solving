#include <bits/stdc++.h>

using namespace std;

const int dx[4]{-1, 1, 0, 0};
const int dy[4]{0, 0, 1, -1};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int R{}, C{}, M{};
	cin >> R >> C >> M;
	vector<int> r(M);
	vector<int> c(M);
	vector<int> s(M);
	vector<int> d(M);
	vector<int> z(M);
	for (int i = 0; i < M; ++i) {
		cin >> r[i] >> c[i] >> s[i] >> d[i] >> z[i];
		s[i] %= 2 * ((--d[i] < 2 ? R : C) - 1);
	}
	vector<vector<int>> A(R + 1, vector<int>(C + 1, -1));
	int ans{};
	for (int i = 1; i <= C; ++i) {
		for (int j = 1; j <= R; ++j) {
			fill(A[j].begin(), A[j].end(), -1);
		}
		for (int j = 0; j < M; ++j) {
			if (z[j] == -1) {
				continue;
			}
			int &u = A[r[j]][c[j]];
			if (u == -1) {
				u = j;
			} else if (z[u] < z[j]) {
				z[u] = -1;
				u = j;
			} else {
				z[j] = -1;
			}
		}
		for (int j = 1; j <= R; ++j) {
			int &u = A[j][i];
			if (u == -1) {
				continue;
			}
			ans += z[u];
			z[u] = -1;
			break;
		}
		for (int j = 0; j < M; ++j) {
			if (z[j] == -1) {
				continue;
			}
			r[j] += s[j] * dx[d[j]];
			c[j] += s[j] * dy[d[j]];
			for (int k = 0; k < 2; ++k) {
				if (1 <= r[j] && r[j] <= R && 1 <= c[j] && c[j] <= C) {
					break;
				}
				if (r[j] < 1) {
					r[j] = 2 - r[j];
				} else if (r[j] > R) {
					r[j] = 2 * R - r[j];
				} else if (c[j] < 1) {
					c[j] = 2 - c[j];
				} else {
					c[j] = 2 * C - c[j];
				}
				d[j] ^= 1;
			}
		}
	}
	cout << ans << "\n";
	return 0;
}
