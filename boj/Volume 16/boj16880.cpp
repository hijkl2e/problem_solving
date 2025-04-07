#include <bits/stdc++.h>

using namespace std;

const int dx[3]{-1, 0, -1};
const int dy[3]{0, -1, -1};

vector<vector<int>> solve(int t) {
	int sz = t ? 12 : 8;
	vector<vector<int>> dp(sz, vector<int>(sz));
	deque<bool> vst(sz);
	for (int i = 0; i < sz; ++i) {
		for (int j = 0; j < sz; ++j) {
			fill(vst.begin(), vst.end(), false);
			for (int k = t ? 2 : 1; k >= 0; --k) {
				int nx = i + dx[k];
				int ny = j + dy[k];
				while (nx >= 0 && ny >= 0) {
					vst[dp[nx][ny]] = true;
					if (k == 2) {
						break;
					}
					nx += dx[k];
					ny += dy[k];
				}
			}
			for (int k = 0; vst[k]; ++k) {
				dp[i][j] = k + 1;
			}
		}
	}
	return dp;
}

int rook(int x, int y) {
	static vector<vector<int>> dp = solve(0);
	int ret{}, k = 1;
	while (x || y) {
		ret += k * dp[x % 8][y % 8];
		x /= 8, y /= 8, k *= 8;
	}
	return ret;
}

int bishop(int x, int y) {
	return min(x, y);
}

int king(int x, int y) {
	return x % 2 ? y % 2 ? 2 : y < x ? 1 : 3 : y % 2 ? y < x ? 3 : 1 : 0;
}

int knight(int x, int y) {
	int z = min(x, y) / 3 * 3;
	x -= z, y -= z;
	return (x == 0 || y == 0 || x + y == 2) ? 0 : (x == 1 || y == 1 || x + y < 6) ? 1 : 2;
}

int palace(int x, int y) {
	static vector<vector<int>> dp = solve(1);
	return dp[x % 12][y % 12] + 12 * rook(x / 12, y / 12);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	int ans{};
	while (N--) {
		int x{}, y{};
		char c{};
		cin >> x >> y >> c;
		if (c == 'R') {
			ans ^= rook(x, y);
		} else if (c == 'B') {
			ans ^= bishop(x, y);
		} else if (c == 'K') {
			ans ^= king(x, y);
		} else if (c == 'N') {
			ans ^= knight(x, y);
		} else {
			ans ^= palace(x, y);
		}
	}
	cout << (ans ? "koosaga" : "cubelover") << "\n";
	return 0;
}
