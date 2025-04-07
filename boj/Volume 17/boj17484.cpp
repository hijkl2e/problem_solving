#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9 + 7;
const int dx[3]{-1, 0, 1};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, M{};
	cin >> N >> M;
	vector<vector<int>> A(N, vector<int>(M));
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			cin >> A[i][j];
		}
	}
	vector<vector<int>> dp1(M, vector<int>(3));
	vector<vector<int>> dp2(M, vector<int>(3));
	for (int i = 0; i < N; ++i) {
		swap(dp1, dp2);
		for (int j = 0; j < M; ++j) {
			fill(dp2[j].begin(), dp2[j].end(), INF);
		}
		for (int j = 0; j < M; ++j) {
			for (int k = 0; k < 3; ++k) {
				for (int l = 0; l < 3; ++l) {
					int nx = j + dx[l];
					if (k == l || nx < 0 || nx >= M) {
						continue;
					}
					dp2[nx][l] = min(dp2[nx][l], dp1[j][k] + A[i][nx]);
				}
			}
		}
	}
	int ans = INF;
	for (int i = 0; i < M; ++i) {
		ans = min(ans, *min_element(dp2[i].begin(), dp2[i].end()));
	}
	cout << ans << "\n";
	return 0;
}
