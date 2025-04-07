#include <bits/stdc++.h>

using namespace std;

const int dx[4]{1, -1, 0, 0};
const int dy[4]{0, 0, 1, -1};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, M{}, K{};
	cin >> N >> M >> K;
	cin.ignore();
	vector<string> A(N);
	for (int i = 0; i < N; ++i) {
		getline(cin, A[i]);
	}
	string S;
	getline(cin, S);
	vector<vector<int>> dp1(N, vector<int>(M));
	vector<vector<int>> dp2(N, vector<int>(M));
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			if (A[i][j] == S[0]) {
				dp2[i][j] = 1;
			}
		}
	}
	for (int n = 0; n < S.size() - 1; ++n) {
		swap(dp1, dp2);
		for (int i = 0; i < N; ++i) {
			fill(dp2[i].begin(), dp2[i].end(), 0);
		}
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < M; ++j) {
				if (A[i][j] != S[n]) {
					continue;
				}
				for (int k = 0; k < 4; ++k) {
					int nx = i, ny = j;
					for (int l = 0; l < K; ++l) {
						nx += dx[k];
						ny += dy[k];
						if (nx == -1 || nx == N || ny == -1 || ny == M) {
							break;
						}
						if (A[nx][ny] == S[n + 1]) {
							dp2[nx][ny] += dp1[i][j];
						}
					}
				}
			}
		}
	}
	int ans{};
	for (int i = 0; i < N; ++i) {
		ans += accumulate(dp2[i].begin(), dp2[i].end(), 0);
	}
	cout << ans << "\n";
	return 0;
}
