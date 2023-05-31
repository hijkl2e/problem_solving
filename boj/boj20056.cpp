#include <bits/stdc++.h>

using namespace std;

using iii = tuple<int, int, int>;

const int dx[8]{-1, -1, 0, 1, 1, 1, 0, -1};
const int dy[8]{0, 1, 1, 1, 0, -1, -1, -1};

vector<iii> A[51][51];
vector<iii> B[51][51];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, M{}, K{};
	cin >> N >> M >> K;
	while (M--) {
		int r{}, c{}, m{}, s{}, d{};
		cin >> r >> c >> m >> s >> d;
		A[r - 1][c - 1].push_back({m, s, d});
	}
	while (K--) {
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < N; ++j) {
				B[i][j].clear();
			}
		}
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < N; ++j) {
				for (auto &[m, s, d] : A[i][j]) {
					int nx = i + s * dx[d];
					int ny = j + s * dy[d];
					nx = (nx % N + N) % N;
					ny = (ny % N + N) % N;
					B[nx][ny].push_back({m, s, d});
				}
			}
		}
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < N; ++j) {
				if (B[i][j].size() < 2) {
					continue;
				}
				int cnt = B[i][j].size();
				int m_sum{}, s_sum{}, d_sum{};
				for (auto &[m, s, d] : B[i][j]) {
					m_sum += m;
					s_sum += s;
					d_sum += d % 2;
				}
				B[i][j].clear();
				if (m_sum / 5 == 0) {
					continue;
				}
				for (int k = 0; k < 4; ++k) {
					B[i][j].push_back({m_sum / 5, s_sum / cnt, 2 * k + (d_sum && d_sum < cnt)});
				}
			}
		}
		swap(A, B);
	}
	int ans{};
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			for (auto &[m, s, d] : A[i][j]) {
				ans += m;
			}
		}
	}
	cout << ans << "\n";
	return 0;
}
