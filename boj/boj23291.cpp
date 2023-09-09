#include <bits/stdc++.h>

using namespace std;

const int dx[4]{1, -1, 0, 0};
const int dy[4]{0, 0, 1, -1};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, K{};
	cin >> N >> K;
	vector<vector<int>> A(N, vector<int>(1));
	for (int i = 0; i < N; ++i) {
		cin >> A[i][0];
	}
	int ans{};
	while ((*max_element(A.begin(), A.end()))[0] - (*min_element(A.begin(), A.end()))[0] > K) {
		int minv = (*min_element(A.begin(), A.end()))[0];
		for (int i = 0; i < N; ++i) {
			if (A[i][0] == minv) {
				++A[i][0];
			}
		}
		for (int l = 0; l < 2; ++l) {
			if (l) {
				int M = N / 4;
				for (int i = 0; i < 3 * M; ++i) {
					int p = 3 * M + (M <= i && i < 2 * M ? (i % M) : (M - i % M - 1));
					A[p].push_back(A[i][0]);
					A[i].clear();
				}
			} else {
				int p{};
				while (p + A[p].size() < N) {
					for (int i = p++; i >= 0 && A[i].size(); --i) {
						for (int j = 0; j < A[i].size(); ++j) {
							A[p + j].push_back(A[i][j]);
						}
						A[i].clear();
					}
					while (p + 1 < N && A[p + 1].size() > 1) {
						++p;
					}
				}
			}
			vector<vector<int>> B = A;
			for (int i = 0; i < N; ++i) {
				for (int j = 0; j < A[i].size(); ++j) {
					for (int k = 0; k < 4; ++k) {
						int nx = i + dx[k];
						int ny = j + dy[k];
						if (0 <= nx && nx < N && 0 <= ny && ny < A[nx].size()
								&& (B[i][j] - B[nx][ny]) / 5 > 0) {
							int d = (B[i][j] - B[nx][ny]) / 5;
							A[i][j] -= d;
							A[nx][ny] += d;
						}
					}
				}
			}
			for (int i = 0, j = 0; i < N; ++i) {
				while (A[i].size() && j <= i) {
					A[j++].push_back(A[i][0]);
					A[i].erase(A[i].begin());
				}
			}
		}
		++ans;
	}
	cout << ans << "\n";
	return 0;
}
