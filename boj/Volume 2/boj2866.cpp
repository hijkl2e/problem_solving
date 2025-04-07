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
	vector<string> B(C);
	for (int i = 0; i < C; ++i) {
		B[i].resize(R);
		for (int j = 0; j < R; ++j) {
			B[i][j] = A[R - j - 1][i];
		}
	}
	sort(B.begin(), B.end());
	int ans = R - 1;
	for (int i = 0; i < C - 1; ++i) {
		for (int j = 0; j < R; ++j) {
			if (B[i][j] != B[i + 1][j]) {
				ans = min(ans, R - j - 1);
				break;
			}
		}
	}
	cout << ans << "\n";
	return 0;
}
