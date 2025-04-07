#include <bits/stdc++.h>

using namespace std;

using ii = pair<int, int>;

const int dx[4]{0, 1, 0, -1};
const int dy[4]{-1, 0, 1, 0};
const int xd[10]{0, -1, 1, -2, 2, -1, 1, -1, 1, 0};
const int yd[10]{-2, -1, -1, 0, 0, 0, 0, 1, 1, -1};
const int zd[10]{5, 10, 10, 2, 2, 7, 7, 1, 1, -1};

ii convert(int x, int y, int d) {
	if (d > 1) {
		x *= -1;
	}
	if (d && d < 3) {
		y *= -1;
	}
	if (d % 2) {
		swap(x, y);
	}
	return {x, y};
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	vector<vector<int>> A(N, vector<int>(N));
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			cin >> A[i][j];
		}
	}
	int x{}, y{}, d{}, z1{}, z2{}, ans{};
	x = y = N / 2;
	while (x || y) {
		x += dx[d];
		y += dy[d];
		int z = A[x][y];
		for (int i = 0; i < 10; ++i) {
			auto [cx, cy] = convert(xd[i], yd[i], d);
			int nx = x + cx;
			int ny = y + cy;
			int k = i == 9 ? A[x][y] : (z * zd[i] / 100);
			A[x][y] -= k;
			if (0 <= nx && nx < N && 0 <= ny && ny < N) {
				A[nx][ny] += k;
			} else {
				ans += k;
			}
		}
		if (z2-- == 0) {
			z2 = ++z1 / 2;
			d = (d + 1) % 4;
		}
	}
	cout << ans << "\n";
	return 0;
}
