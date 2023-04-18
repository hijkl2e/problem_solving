#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int h1{}, w1{};
	cin >> h1 >> w1;
	cin.ignore();
	vector<string> A(h1);
	for (int i = 0; i < h1; ++i) {
		getline(cin, A[i]);
	}
	int h2{}, w2{};
	cin >> h2 >> w2;
	cin.ignore();
	vector<string> B(h2);
	for (int i = 0; i < h2; ++i) {
		getline(cin, B[i]);
	}
	int ans{};
	for (int i = 0; i < h1; ++i) {
		for (int j = 0; j < w1; ++j) {
			if (A[i][j] == 'O') {
				ans = 1e9;
			}
		}
	}
	for (int i = 0; i < h1; ++i) {
		for (int j = 0; j < w1; ++j) {
			if (A[i][j] == '.') {
				continue;
			}
			for (int k = 0; k < h2; ++k) {
				for (int l = 0; l < w2; ++l) {
					if (B[k][l] == '.') {
						continue;
					}
					int d1 = k - i;
					int d2 = l - j;
					int cnt{};
					for (int m = 0; m < h1; ++m) {
						for (int n = 0; n < w1; ++n) {
							if (A[m][n] == '.') {
								continue;
							}
							++cnt;
							if (0 <= m + d1 && m + d1 < h2 && 0 <= n + d2 && n + d2 < w2
									&& B[m + d1][n + d2] == 'O') {
								--cnt;
							}
						}
					}
					ans = min(ans, cnt);
				}
			}
		}
	}
	cout << ans << "\n";
	return 0;
}
