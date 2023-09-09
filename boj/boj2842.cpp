#include <bits/stdc++.h>

using namespace std;

using iii = tuple<int, int, int>;

const int dx[8]{-1, -1, -1, 0, 1, 1, 1, 0};
const int dy[8]{-1, 0, 1, 1, 1, 0, -1, -1};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	cin.ignore();
	vector<string> A(N);
	for (int i = 0; i < N; ++i) {
		getline(cin, A[i]);
	}
	vector<vector<int>> B(N, vector<int>(N));
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			cin >> B[i][j];
		}
	}
	vector<int> C(N * N);
	int sx{}, sy{}, K{};
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			if (A[i][j] == 'P') {
				sx = i, sy = j;
			} else if (A[i][j] == 'K') {
				++K;
			}
			C[i * N + j] = B[i][j];
		}
	}
	sort(C.begin(), C.end());
	C.resize(unique(C.begin(), C.end()) - C.begin());
	vector<deque<bool>> D(N, deque<bool>(N));
	int ans = 1e9;
	for (int minh : C) {
		for (int i = 0; i < N; ++i) {
			fill(D[i].begin(), D[i].end(), false);
		}
		priority_queue<iii, vector<iii>, greater<iii>> pq;
		D[sx][sy] = true;
		pq.push({B[sx][sy], sx, sy});
		int maxh{}, cnt{};
		while (pq.size()) {
			auto [h, x, y] = pq.top(); pq.pop();
			maxh = max(maxh, h);
			if (A[x][y] == 'K') {
				if (++cnt == K) {
					ans = min(ans, maxh - minh);
					break;
				}
			}
			for (int i = 0; i < 8; ++i) {
				int nx = x + dx[i];
				int ny = y + dy[i];
				if (0 <= nx && nx < N && 0 <= ny && ny < N && !D[nx][ny] && B[nx][ny] >= minh) {
					D[nx][ny] = true;
					pq.push({B[nx][ny], nx, ny});
				}
			}
		}
		if (B[sx][sy] == minh || cnt < K) {
			break;
		}
	}
	cout << ans << "\n";
	return 0;
}
