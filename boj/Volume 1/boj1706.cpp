#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int R{}, C{};
	cin >> R >> C;
	cin.ignore();
	vector<string> A(R);
	for (int i = 0; i < R; ++i) {
		getline(cin, A[i]);
	}
	string ans = "|";
	for (int q = 0; q < 2; ++q) {
		for (int i = 0; i < R; ++i) {
			for (int j = 0, k = 1; j < C; j = k++) {
				if (A[i][j] == '#') {
					continue;
				}
				while (k < C && A[i][k] != '#') {
					++k;
				}
				if (k - j > 1) {
					ans = min(ans, string(A[i].substr(j, k - j)));
				}
			}
		}
		if (q == 0) {
			vector<string> B(C, string(R, '#'));
			for (int i = 0; i < R; ++i) {
				for (int j = 0; j < C; ++j) {
					B[j][i] = A[i][j];
				}
			}
			swap(R, C);
			swap(A, B);
		}
	}
	cout << ans << "\n";
	return 0;
}
