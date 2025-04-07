#include <bits/stdc++.h>

using namespace std;

using iii = tuple<int, int, int>;

int D[21][21][21];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, sx{}, sy{}, M{};
	cin >> N >> sx >> sy >> M;
	vector<int> A(M);
	for (int i = 0; i < M; ++i) {
		cin >> A[i];
	}
	memset(D, -1, sizeof D);
	deque<iii> dq;
	D[0][sx][sy] = 0;
	dq.push_back({0, sx, sy});
	int ans{};
	while (dq.size()) {
		auto [p, x, y] = dq.front(); dq.pop_front();
		if (p == M) {
			ans = D[p][x][y];
			break;
		}
		if (A[p] == x || A[p] == y) {
			if (D[p + 1][x][y] == -1) {
				D[p + 1][x][y] = D[p][x][y];
				dq.push_front({p + 1, x, y});
			}
			continue;
		}
		if (x > 1 && D[p][x - 1][y] == -1) {
			D[p][x - 1][y] = D[p][x][y] + 1;
			dq.push_back({p, x - 1, y});
		}
		if (y < N && D[p][x][y + 1] == -1) {
			D[p][x][y + 1] = D[p][x][y] + 1;
			dq.push_back({p, x, y + 1});
		}
		if (x + 1 < y && D[p][x + 1][y] == -1) {
			D[p][x + 1][y] = D[p][x][y] + 1;
			dq.push_back({p, x + 1, y});
		}
		if (x < y - 1 && D[p][x][y - 1] == -1) {
			D[p][x][y - 1] = D[p][x][y] + 1;
			dq.push_back({p, x, y - 1});
		}
	}
	cout << ans << "\n";
	return 0;
}
