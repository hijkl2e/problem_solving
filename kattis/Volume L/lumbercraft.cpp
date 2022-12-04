#include <bits/stdc++.h>

using namespace std;

using ii = pair<int, int>;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, H{}, W{};
	while (cin >> N >> H >> W, N) {
		cin.ignore();
		vector<string> A(H);
		for (int i = 0; i < H; ++i) {
			getline(cin, A[i]);
		}
		vector<ii> B(26, {-1, -1});
		for (int i = 0; i < H; ++i) {
			for (int j = 0; j < W; ++j) {
				if (isalpha(A[i][j])) {
					B[A[i][j] - 'A'] = {i, j};
				}
			}
		}
		vector<vector<int>> C(H, vector<int>(W));
		while (N--) {
			for (int k = 0; k < 26; ++k) {
				auto &[sx, sy] = B[k];
				if (sx == -1) {
					continue;
				}
				int x = -1, y = -1, d = 1e9;
				for (int i = 0; i < H; ++i) {
					for (int j = 0; j < W; ++j) {
						if (A[i][j] != '!') {
							continue;
						}
						int nd = (i - sx) * (i - sx) + (j - sy) * (j - sy);
						if (d > nd || (d == nd && y < j) || (d == nd && y == j && x < i)) {
							x = i;
							y = j;
							d = nd;
						}
					}
				}
				if (x == -1) {
					continue;
				}
				C[x][y] |= 1 << k;
			}
			for (int i = 0; i < H; ++i) {
				for (int j = 0; j < W; ++j) {
					if (C[i][j]) {
						A[i][j] = '.';
					}
				}
			}
		}
		for (int i = 0; i < H; ++i) {
			cout << A[i] << "\n";
		}
		cout << fixed << setprecision(10);
		for (int k = 0; k < 26; ++k) {
			if (B[k].first == -1) {
				continue;
			}
			double ans{};
			for (int i = 0; i < H; ++i) {
				for (int j = 0; j < W; ++j) {
					if (C[i][j] & (1 << k)) {
						ans += 1.0 / __builtin_popcount(C[i][j]);
					}
				}
			}
			char c = 'A' + k;
			cout << c << " " << ans << "\n";
		}
		cout << "\n";
	}
	return 0;
}
