#include <bits/stdc++.h>

using namespace std;

const int dx[4]{1, -1, 0, 0};
const int dy[4]{0, 0, 1, -1};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	vector<vector<int>> A(N * N, vector<int>(5));
	for (int i = 0; i < A.size(); ++i) {
		for (int j = 0; j < 5; ++j) {
			cin >> A[i][j];
		}
	}
	vector<vector<int>> B(N, vector<int>(N));
	for (int n = 0; n < A.size(); ++n) {
		int x{}, y{}, c1{}, c2 = -1;
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < N; ++j) {
				if (B[i][j]) {
					continue;
				}
				int d1{}, d2{};
				for (int k = 0; k < 4; ++k) {
					int nx = i + dx[k];
					int ny = j + dy[k];
					if (0 <= nx && nx < N && 0 <= ny && ny < N) {
						if (B[nx][ny]) {
							d1 += find(A[n].begin() + 1, A[n].end(), B[nx][ny]) != A[n].end();
						} else {
							++d2;
						}
					}
				}
				if (c1 < d1 || (c1 == d1 && c2 < d2)) {
					x = i, y = j;
					c1 = d1, c2 = d2;
				}
			}
		}
		B[x][y] = A[n][0];
	}
	sort(A.begin(), A.end());
	int ans{};
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			auto &v = A[B[i][j] - 1];
			int cnt{};
			for (int k = 0; k < 4; ++k) {
				int nx = i + dx[k];
				int ny = j + dy[k];
				if (0 <= nx && nx < N && 0 <= ny && ny < N) {
					cnt += find(v.begin() + 1, v.end(), B[nx][ny]) != v.end();
				}
			}
			ans += cnt == 4 ? 1000 : cnt == 3 ? 100 : cnt == 2 ? 10 : cnt;
		}
	}
	cout << ans << "\n";
	return 0;
}
