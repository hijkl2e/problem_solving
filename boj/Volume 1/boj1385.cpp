#include <bits/stdc++.h>

using namespace std;

using ii = pair<int, int>;

const int dx[6]{0, 1, 1, 0, -1, -1};
const int dy[6]{2, 1, -1, -2, -1, 1};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int a{}, b{};
	cin >> a >> b;
	vector<vector<int>> A(1201, vector<int>(2401, -1));
	int p{}, x{}, y{}, d{}, z{}, zz{};
	x = 600, y = 1200, z = zz = 1;
	int sx{}, sy{}, gx{}, gy{};
	while (zz < 579) {
		A[x][y] = ++p;
		if (p == a) {
			sx = x, sy = y;
		}
		if (p == b) {
			gx = x, gy = y;
		}
		x += dx[d], y += dy[d];
		if (--z == 0) {
			zz += d == 5;
			d = (d + (p == 1 ? 2 : 1)) % 6;
			z = zz - (d == 1);
		}
	}
	vector<vector<int>> D(1201, vector<int>(2401, -1));
	vector<vector<int>> par(1201, vector<int>(2401, -1));
	queue<ii> q;
	D[sx][sy] = 0;
	q.push({sx, sy});
	while (q.size()) {
		auto [x, y] = q.front(); q.pop();
		for (int i = 0; i < 6; ++i) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (A[nx][ny] != -1 && D[nx][ny] == -1) {
				D[nx][ny] = D[x][y] + 1;
				par[nx][ny] = i;
				q.push({nx, ny});
			}
		}
	}
	vector<int> B;
	B.push_back(b);
	while (a != b) {
		int d = par[gx][gy];
		gx -= dx[d];
		gy -= dy[d];
		b = A[gx][gy];
		B.push_back(b);
	}
	reverse(B.begin(), B.end());
	for (int i = 0; i < B.size(); ++i) {
		cout << B[i] << (i == B.size() - 1 ? "\n" : " ");
	}
	return 0;
}
