#include <bits/stdc++.h>

using namespace std;

const int dx[4]{1, -1, 0, 0};
const int dy[4]{0, 0, 1, -1};

int N, M, ans;
vector<string> A;

void solve(int n, int x) {
	if (n == 2) {
		ans = max(ans, x);
		return;
	}
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			if (A[i][j] == '.') {
				continue;
			}
			int k{};
			bool flag = true;
			while (flag) {
				++k;
				for (int l = 0; l < 4; ++l) {
					int nx = i + k * dx[l];
					int ny = j + k * dy[l];
					if (nx == -1 || nx == N || ny == -1 || ny == M || A[nx][ny] == '.') {
						flag = false;
						break;
					}
				}
			}
			for (int m = 0; m < k; ++m) {
				for (int l = 0; l < 4; ++l) {
					int nx = i + m * dx[l];
					int ny = j + m * dy[l];
					A[nx][ny] = '.';
				}
			}
			for (--k; k >= 0; --k) {
				solve(n + 1, x * (4 * k + 1));
				for (int l = 0; l < 4; ++l) {
					int nx = i + k * dx[l];
					int ny = j + k * dy[l];
					A[nx][ny] = '#';
				}
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> N >> M;
	cin.ignore();
	A.resize(N);
	for (int i = 0; i < N; ++i) {
		getline(cin, A[i]);
	}
	solve(0, 1);
	cout << ans << "\n";
	return 0;
}
