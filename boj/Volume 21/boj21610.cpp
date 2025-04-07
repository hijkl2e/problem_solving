#include <bits/stdc++.h>

using namespace std;

using ii = pair<int, int>;

const int dx[8]{0, -1, -1, -1, 0, 1, 1, 1};
const int dy[8]{-1, -1, 0, 1, 1, 1, 0, -1};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, M{};
	cin >> N >> M;
	vector<vector<int>> A(N, vector<int>(N));
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			cin >> A[i][j];
		}
	}
	vector<ii> B{
		{N - 1, 0}, {N - 1, 1}, {N - 2, 0}, {N - 2, 1}
	};
	vector<deque<bool>> C(N, deque<bool>(N));
	while (M--) {
		int d{}, s{};
		cin >> d >> s;
		--d;
		for (int i = 0; i < N; ++i) {
			fill(C[i].begin(), C[i].end(), false);
		}
		for (auto &[x, y] : B) {
			x += s * dx[d];
			y += s * dy[d];
			x = (x % N + N) % N;
			y = (y % N + N) % N;
			C[x][y] = true;
			++A[x][y];
		}
		for (auto &[x, y] : B) {
			for (int i = 1; i < 8; i += 2) {
				int nx = x + dx[i];
				int ny = y + dy[i];
				if (0 <= nx && nx < N && 0 <= ny && ny < N && A[nx][ny]) {
					++A[x][y];
				}
			}
		}
		B.clear();
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < N; ++j) {
				if (A[i][j] >= 2 && !C[i][j]) {
					A[i][j] -= 2;
					B.push_back({i, j});
				}
			}
		}
	}
	int ans{};
	for (int i = 0; i < N; ++i) {
		ans += accumulate(A[i].begin(), A[i].end(), 0);
	}
	cout << ans << "\n";
	return 0;
}
