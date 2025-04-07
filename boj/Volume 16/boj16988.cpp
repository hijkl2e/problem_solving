#include <bits/stdc++.h>

using namespace std;

using ii = pair<int, int>;
using rec = pair<ii, ii>;

const int dx[4]{1, -1, 0, 0};
const int dy[4]{0, 0, 1, -1};

int N, M;
vector<vector<int>> A;
map<rec, int> B;

void bfs(int sx, int sy) {
	queue<ii> q;
	A[sx][sy] = -1;
	q.push({sx, sy});
	vector<ii> C;
	int cnt{};
	while (q.size()) {
		auto [x, y] = q.front(); q.pop();
		for (int i = 0; i < 4; ++i) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (0 <= nx && nx < N && 0 <= ny && ny < M) {
				if (A[nx][ny] == 2) {
					A[nx][ny] = -1;
					q.push({nx, ny});
				} else if (A[nx][ny] == 0) {
					C.push_back({nx, ny});
				}
			}
		}
		++cnt;
	}
	sort(C.begin(), C.end());
	C.resize(unique(C.begin(), C.end()) - C.begin());
	if (C.size() > 2) {
		return;
	} else if (C.size() == 1) {
		C.push_back({-1, -1});
	}
	B[{C[0], C[1]}] += cnt;
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
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			if (A[i][j] == 2) {
				bfs(i, j);
			}
		}
	}
	vector<int> C;
	int ans{};
	for (auto &[k, v] : B) {
		auto &[x1, y1] = k.first;
		auto &[x2, y2] = k.second;
		if (x2 == -1) {
			C.push_back(v);
			continue;
		}
		auto it1 = B.find({{x1, y1}, {-1, -1}});
		auto it2 = B.find({{x2, y2}, {-1, -1}});
		ans = max(ans, v + (it1 == B.end() ? 0 : it1->second) + (it2 == B.end() ? 0 : it2->second));
	}
	sort(C.rbegin(), C.rend());
	ans = max(ans, (C.size() ? C[0] : 0) + (C.size() > 1 ? C[1] : 0));
	cout << ans << "\n";
	return 0;
}
