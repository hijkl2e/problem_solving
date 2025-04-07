#include <bits/stdc++.h>

using namespace std;

using ii = pair<int, int>;

const int dx[4]{1, -1, 0, 0};
const int dy[4]{0, 0, 1, -1};

int N, M;
vector<vector<int>> A;
vector<vector<ii>> B;

void solve() {
	queue<vector<ii>> q;
	q.push({{0, 0}});
	while (q.size()) {
		auto vx = q.front(); q.pop();
		if (vx.size() == 6) {
			B.push_back(vx);
			continue;
		}
		for (auto &[x, y] : vx) {
			for (int i = 0; i < 4; ++i) {
				int nx = x + dx[i];
				int ny = y + dy[i];
				if (find(vx.begin(), vx.end(), make_pair(nx, ny)) != vx.end()) {
					continue;
				}
				auto vy = vx;
				vy.push_back({nx, ny});
				sort(vy.begin(), vy.end());
				if (vy[0] == make_pair(0, 0)) {
					q.push(vy);
				}
			}
		}
	}
}

int solve(int sx, int sy) {
	int ret{};
	for (auto &v : B) {
		int sum{};
		for (auto &[dx, dy] : v) {
			int nx = sx + dx;
			int ny = sy + dy;
			if (0 <= nx && nx < N && 0 <= ny && ny < M) {
				sum += A[nx][ny];
			} else {
				sum = -1;
				break;
			}
		}
		ret = max(ret, sum);
	}
	return ret;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> N >> M;
	A.assign(N, vector<int>(M));
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			cin >> A[i][j];
		}
	}
	solve();
	sort(B.begin(), B.end());
	B.resize(unique(B.begin(), B.end()) - B.begin());
	int ans{};
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			ans = max(ans, solve(i, j));
		}
	}
	cout << ans << "\n";
	return 0;
}
