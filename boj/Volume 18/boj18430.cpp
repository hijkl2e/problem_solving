#include <bits/stdc++.h>

using namespace std;

const int dx[4]{-1, 0, 1, 0};
const int dy[4]{0, 1, 0, -1};

int N, M;

int f(int x, int y) {
	return (1 << (M * x + y));
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> N >> M;
	vector<vector<int>> A(N, vector<int>(M));
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			cin >> A[i][j];
		}
	}
	map<int, int> B;
	B[0] = 0;
	auto it = B.begin();
	while (it != B.end()) {
		auto &[b, v] = *it;
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < M; ++j) {
				if (b & f(i, j)) {
					continue;
				}
				for (int k = 0; k < 4; ++k) {
					int nx1 = i + dx[k];
					int ny1 = j + dy[k];
					int nx2 = i + dx[(k + 1) % 4];
					int ny2 = j + dy[(k + 1) % 4];
					if (0 <= nx1 && nx1 < N && 0 <= ny1 && ny1 < M
						&& 0 <= nx2 && nx2 < N && 0 <= ny2 && ny2 < M
						&& (b & f(nx1, ny1)) == 0
						&& (b & f(nx2, ny2)) == 0) {
						int &nv = B[b | f(i, j) | f(nx1, ny1) | f(nx2, ny2)];
						nv = max(nv, v + 2 * A[i][j] + A[nx1][ny1] + A[nx2][ny2]);
					}
				}
			}
		}
		++it;
	}
	int ans{};
	for (auto &[b, w] : B) {
		ans = max(ans, w);
	}
	cout << ans << "\n";
	return 0;
}
