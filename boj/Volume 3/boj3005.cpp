#include <bits/stdc++.h>

using namespace std;

string solve(int R, int C, vector<string> &A) {
	string ans = "|";
	for (int i = 0; i < R; ++i) {
		int beg{};
		for (int j = 0; j < C; ++j) {
			if (A[i][j] == '#') {
				if (j - beg > 1) {
					ans = min(ans, A[i].substr(beg, j - beg));
				}
				beg = j + 1;
			}
		}
		if (C - beg > 1) {
			ans = min(ans, A[i].substr(beg));
		}
	}
	return ans;
}

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
	vector<string> B(C, string(R, ' '));
	for (int i = 0; i < C; ++i) {
		for (int j = 0; j < R; ++j) {
			B[i][j] = A[j][i];
		}
	}
	string ans = min(solve(R, C, A), solve(C, R, B));
	cout << ans << "\n";
	return 0;
}
