#include <bits/stdc++.h>

using namespace std;

using ii = pair<int, int>;

const int INF = 1e9 + 7;
const int dx[4]{1, -1, 0, 0};
const int dy[4]{0, 0, 1, -1};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, M{}, T{}, K{};
	cin >> N >> M >> T >> K;
	cin.ignore();
	vector<string> A(N);
	for (int i = 0; i < N; ++i) {
		getline(cin, A[i]);
	}
	vector<vector<int>> B(N, vector<int>(M));
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			if (isupper(A[i][j])) {
				B[i][j] = A[i][j] - 'A';
			} else {
				B[i][j] = A[i][j] - 'a' + 26;
			}
		}
	}
	vector<vector<int>> D1(N, vector<int>(M, INF));
	vector<vector<int>> D2(N, vector<int>(M, INF));
	for (int k = 0; k < 2; ++k) {
		priority_queue<ii, vector<ii>, greater<ii>> pq;
		pq.push({D1[0][0] = 0, 0});
		while (pq.size()) {
			auto [d, u] = pq.top(); pq.pop();
			int x = u / M, y = u % M;
			if (D1[x][y] < d) {
				continue;
			}
			for (int i = 0; i < 4; ++i) {
				int nx = x + dx[i];
				int ny = y + dy[i];
				if (0 <= nx && nx < N && 0 <= ny && ny < M && abs(B[nx][ny] - B[x][y]) <= T) {
					int nd = d;
					if (B[nx][ny] == B[x][y] || ((B[nx][ny] < B[x][y]) ^ k)) {
						nd += 1;
					} else {
						nd += (B[nx][ny] - B[x][y]) * (B[nx][ny] - B[x][y]);
					}
					if (D1[nx][ny] > nd) {
						pq.push({D1[nx][ny] = nd, nx * M + ny});
					}
				}
			}
		}
		swap(D1, D2);
	}
	int ans{};
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			if (D1[i][j] + D2[i][j] <= K) {
				ans = max(ans, B[i][j]);
			}
		}
	}
	cout << ans << "\n";
	return 0;
}
