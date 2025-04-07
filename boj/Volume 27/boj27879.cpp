#include <bits/stdc++.h>

using namespace std;

int A[1001][1001];
int B[8][1001][1001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= N; ++j) {
			char c{};
			cin >> c;
			A[i][j] = c == 'b';
		}
	}
	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= N; ++j) {
			if (i < N) {
				++B[2 * A[i][j] + A[i + 1][j]][i][j];
			}
			if (j < N) {
				++B[2 * A[i][j] + A[i][j + 1] + 4][i][j];
			}
		}
	}
	for (int k = 0; k < 8; ++k) {
		for (int i = 1; i <= N; ++i) {
			for (int j = 1; j <= N; ++j) {
				B[k][i][j] += B[k][i - 1][j] + B[k][i][j - 1] - B[k][i - 1][j - 1];
			}
		}
	}
	int Q{};
	cin >> Q;
	while (Q--) {
		int x1{}, y1{}, x2{}, y2{};
		string s;
		cin >> x1 >> y1 >> x2 >> y2 >> s;
		int z = 2 * (s[0] - 'a') + (s[1] - 'a');
		int ans = B[z][x2 - 1][y2] - B[z][x1 - 1][y2] - B[z][x2 - 1][y1 - 1] + B[z][x1 - 1][y1 - 1];
		z += 4;
		ans += B[z][x2][y2 - 1] - B[z][x1 - 1][y2 - 1] - B[z][x2][y1 - 1] + B[z][x1 - 1][y1 - 1];
		cout << ans << "\n";
	}
	return 0;
}
