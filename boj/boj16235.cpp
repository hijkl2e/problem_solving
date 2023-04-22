#include <bits/stdc++.h>

using namespace std;

const int dx[8]{-1, -1, -1, 0, 1, 1, 1, 0};
const int dy[8]{-1, 0, 1, 1, 1, 0, -1, -1};

int A[10][10];
int B[10][10];
deque<int> C[10][10];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, M{}, K{};
	cin >> N >> M >> K;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			cin >> A[i][j];
		}
	}
	while (M--) {
		int x{}, y{}, z{};
		cin >> x >> y >> z;
		C[x - 1][y - 1].push_back(z);
	}
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			B[i][j] = 5;
			sort(C[i][j].begin(), C[i][j].end());
		}
	}
	while (K--) {
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < N; ++j) {
				int k{};
				for (; k < C[i][j].size(); ++k) {
					if (B[i][j] < C[i][j][k]) {
						break;
					}
					B[i][j] -= C[i][j][k]++;
				}
				while (C[i][j].size() > k) {
					B[i][j] += C[i][j].back() / 2;
					C[i][j].pop_back();
				}
			}
		}
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < N; ++j) {
				for (int k : C[i][j]) {
					if (k % 5) {
						continue;
					}
					for (int l = 0; l < 8; ++l) {
						int nx = i + dx[l];
						int ny = j + dy[l];
						if (0 <= nx && nx < N && 0 <= ny && ny < N) {
							C[nx][ny].push_front(1);
						}
					}
				}
				B[i][j] += A[i][j];
			}
		}
	}
	int ans{};
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			ans += C[i][j].size();
		}
	}
	cout << ans << "\n";
	return 0;
}
