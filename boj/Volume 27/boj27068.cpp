#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ii = pair<int, int>;

const int dx[4]{1, 0, -1, 0};
const int dy[4]{0, 1, 0, -1};

ll N, M, K, X;
vector<vector<ll>> A, B;

bool solve(ll z) {
	for (int i = 0; i < N; ++i) {
		copy(A[i].begin(), A[i].end(), B[i].begin());
	}
	queue<ii> q;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			bool yes{};
			for (int k = 0; k < 4; ++k) {
				int nx = i + dx[k];
				int ny = j + dy[k];
				if (0 <= nx && nx < N && 0 <= ny && ny < M && B[nx][ny] - B[i][j] > z) {
					yes = true;
					break;
				}
			}
			if (yes) {
				B[i][j] = X;
				q.push({i, j});
			}
		}
	}
	int cnt{};
	while (q.size()) {
		auto [x, y] = q.front(); q.pop();
		++cnt;
		for (int i = 0; i < 4; ++i) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (0 <= nx && nx < N && 0 <= ny && ny < M && B[x][y] - B[nx][ny] > z) {
				B[nx][ny] = X;
				q.push({nx, ny});
			}
		}
	}
	return cnt <= K;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> N >> M >> K >> X;
	A.assign(N, vector<ll>(M));
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			cin >> A[i][j];
		}
	}
	B.assign(N, vector<ll>(M));
	ll lo = -1, hi = X;
	while (lo + 1 < hi) {
		ll mid = (lo + hi) / 2;
		if (solve(mid)) {
			hi = mid;
		} else {
			lo = mid;
		}
	}
	cout << hi << "\n";
	return 0;
}
