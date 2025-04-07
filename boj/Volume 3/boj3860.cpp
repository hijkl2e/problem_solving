#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ii = pair<int, int>;

const ll INF = 4e18;
const int dx[4]{1, -1, 0, 0};
const int dy[4]{0, 0, 1, -1};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, M{};
	while (cin >> N >> M, N) {
		vector<deque<bool>> A(N, deque<bool>(M, true));
		int g{};
		cin >> g;
		while (g--) {
			int x{}, y{};
			cin >> x >> y;
			A[x][y] = false;
		}
		int e{};
		cin >> e;
		int sz = N * M;
		vector<vector<ii>> G(sz);
		while (e--) {
			int x1{}, y1{}, x2{}, y2{}, t{};
			cin >> x1 >> y1 >> x2 >> y2 >> t;
			G[x1 * M + y1].push_back({x2 * M + y2, t});
		}
		for (int i = 0; i < sz - 1; ++i) {
			int x = i / M, y = i % M;
			if (!A[x][y] || G[i].size()) {
				continue;
			}
			for (int j = 0; j < 4; ++j) {
				int nx = x + dx[j];
				int ny = y + dy[j];
				if (0 <= nx && nx < N && 0 <= ny && ny < M && A[nx][ny]) {
					G[i].push_back({nx * M + ny, 1});
				}
			}
		}
		vector<ll> D(sz, INF);
		D[0] = 0;
		bool flag{};
		for (int i = 0; i < sz; ++i) {
			for (int u = 0; u < sz; ++u) {
				if (D[u] == INF) {
					continue;
				}
				for (auto &[v, w] : G[u]) {
					if (D[v] > D[u] + w) {
						D[v] = D[u] + w;
						if (i == sz - 1) {
							flag = true;
						}
					}
				}
			}
		}
		if (flag) {
			cout << "Never\n";
		} else if (D[sz - 1] == INF) {
			cout << "Impossible\n";
		} else {
			cout << D[sz - 1] << "\n";
		}
	}
	return 0;
}
