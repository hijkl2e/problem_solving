#include <bits/stdc++.h>

using namespace std;

const int dx[4]{1, 0, -1, 0};
const int dy[4]{0, -1, 0, 1};

bool A[101][101];

void solve(int &x, int &y, int &d, int g, bool r) {
	if (g == 0) {
		x += dx[d];
		y += dy[d];
		d = (d + 1) % 4;
		A[x][y] = true;
		return;
	}
	solve(x, y, d, g - 1, false);
	d = (d + (r ? 2 : 0)) % 4;
	solve(x, y, d, g - 1, true);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	while (N--) {
		int x{}, y{}, d{}, g{};
		cin >> x >> y >> d >> g;
		A[x][y] = true;
		solve(x, y, d, g, false);
	}
	int ans{};
	for (int i = 0; i < 100; ++i) {
		for (int j = 0; j < 100; ++j) {
			if (A[i][j] && A[i][j + 1] && A[i + 1][j] && A[i + 1][j + 1]) {
				++ans;
			}
		}
	}
	cout << ans << "\n";
	return 0;
}
