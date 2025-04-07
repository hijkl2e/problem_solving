#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using lii = tuple<ll, int, int>;

const ll INF = 4e18;
const int dx[8]{-2, -1, 0, 1, 2, 1, 0, -1};
const int dy[8]{0, 1, 2, 1, 0, -1, -2, -1};
const int dz[8]{8, 10, 2, 6, 4, 5, 1, 9};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	map<char, int> d2i{
		{'L', 0}, {'R', 1}, {'D', 2}, {'U', 3}, {'.', 4}, {'#', 5}
	};
	int N{}, M{};
	cin >> N >> M;
	ll P{}, Q{};
	cin >> P >> Q;
	cin.ignore();
	vector<string> S(N);
	for (int i = 0; i < N; ++i) {
		getline(cin, S[i]);
	}
	vector<vector<ll>> D(N, vector<ll>(M, INF));
	priority_queue<lii, vector<lii>, greater<lii>> pq;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			if (S[i][j] == '.') {
				pq.push({D[i][j] = 0, i, j});
			}
		}
	}
	while (!pq.empty()) {
		auto [d, x, y] = pq.top(); pq.pop();
		if (D[x][y] < d) {
			continue;
		}
		for (int k = 0; k < 8; ++k) {
			int nx = x + dx[k];
			int ny = y + dy[k];
			if (0 <= nx && nx < N && 0 <= ny && ny < M && (dz[k] & (1 << d2i[S[nx][ny]]))) {
				ll nd = d + (k % 2 ? P : Q);
				if (D[nx][ny] > nd) {
					pq.push({D[nx][ny] = nd, nx, ny});
				}
			}
		}
	}
	ll ans = INF;
	for (int i = 0; i < N; ++i) {
		for (int j = (i + 1) % 2; j < M; ++j) {
			for (int k = 0; k < 8; k += 2) {
				int nx = i + dx[k] / 2;
				int ny = j + dy[k] / 2;
				if (0 <= nx && nx < N && 0 <= ny && ny < M) {
					ans = min(ans, D[i][j] + D[nx][ny]);
				}
			}
		}
	}
	cout << (ans == INF ? -1 : ans) << "\n";
	return 0;
}
